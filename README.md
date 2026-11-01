# Материалы курса "Технологии программирования"
# Архитектурное описание системы обработки заказов (Order Processing System)

Данный документ содержит техническую спецификацию и архитектурные диаграммы системы в концепции MBSE (Model-Based Systems Engineering) на базе стандартов **SysML / UML**. Все диаграммы интерактивны и рендерятся нативно средствами GitHub (Mermaid.js).

---

## 1. Спецификация требований (Requirement Diagram)

Диаграмма определяет структуру требований к системе, уровень их критичности (риски) и трассировку до конкретных компонентов архитектуры и тест-кейсов.

```mermaid
requirementDiagram
    requirement REQ1 {
        id: "1"
        text: "Система должна обрабатывать заказ"
        risk: High
        verifymethod: Test
    }
    requirement REQ1_1 {
        id: "1.1"
        text: "Проверять наличие товара"
        risk: Medium
        verifymethod: Test
    }
    requirement REQ1_2 {
        id: "1.2"
        text: "Обрабатывать платеж"
        risk: High
        verifymethod: Test
    }
    requirement REQ1_3 {
        id: "1.3"
        text: "Отправлять уведомление"
        risk: Low
        verifymethod: Test
    }

    element OrderService {
        type: "Class"
    }
    element PaymentGateway {
        type: "Class"
    }
    element EmailService {
        type: "Class"
    }
    element TC_Payment_Test {
        type: "TestCase"
    }

    REQ1 - contains -> REQ1_1
    REQ1 - contains -> REQ1_2
    REQ1 - contains -> REQ1_3

    OrderService - satisfies -> REQ1_1
    PaymentGateway - satisfies -> REQ1_2
    EmailService - satisfies -> REQ1_3

    TC_Payment_Test - verifies -> REQ1_2
```

---

## 2. Границы системы и прецеденты (Use Case Diagram)

Диаграмма вариантов использования определяет внешних актеров и ключевые функции системы, которые декомпозируют верхнеуровневое требование `REQ1`.

```mermaid
flowchart LR
    User((Клиент))
    Manager((Менеджер))

    UC1([Создать заказ])
    UC2([Проверить склад])
    UC3([Оплатить заказ])
    UC4([Отправить уведомление])

    User --> UC1
    User --> UC3
    Manager --> UC2

    UC1 -.-> UC2
    UC1 -.-> UC3
    UC1 -.-> UC4

    style UC1 fill:#f9f,stroke:#333,stroke-width:2px
    style UC2 fill:#bbf,stroke:#333,stroke-width:1px
    style UC3 fill:#bbf,stroke:#333,stroke-width:1px
    style UC4 fill:#bbf,stroke:#333,stroke-width:1px
```

---

## 3. Бизнес-процесс обработки платежа (Activity Diagram)

Диаграмма верхнего уровня (Бизнес-абстракция) для требования `REQ1.2`. Показывает распределение ответственности между Клиентом, Системой и Банком.

```mermaid
flowchart TB
    subgraph Клиент
        A([Начало: Оплата]) --> B[Ввод данных карты]
    end

    subgraph Система [OrderService / Сайт]
        B --> C[Проверка формата полей]
        C -->|Данные некорректны| D[Показать ошибку ввода]
        D --> B
        C -->|Данные верны| E[Шифрование данных]
    end

    subgraph Банк [PaymentGateway]
        E --> F[Запрос на списание средств]
        F --> G{Достаточно средств?}
        G -->|Нет| H[Блокировка: Отказ банка]
        G -->|Да| I[Списание и генерация чека]
    end

    H --> J[Уведомление об ошибке]
    I --> K[Уведомление об успехе]

    subgraph Система [OrderService / Сайт]
        J --> L([Конец: Платеж отклонен])
        K --> M([Конец: Заказ оплачен])
    end

    style Клиент fill:#fff2cc,stroke:#d6b656,stroke-width:2px
    style Система fill:#e1d5e7,stroke:#9673a6,stroke-width:2px
    style Банк fill:#dae8fc,stroke:#6c8ebf,stroke-width:2px
```

---

## 4. Динамическое взаимодействие компонентов (Sequence Diagram)

Пошаговый технический сценарий обработки успешного заказа. Описывает взаимодействие между классами, заявленными в структуре требований.

```mermaid
sequenceDiagram
    autonumber
    actor Client as Клиент
    participant OS as OrderService
    participant PG as PaymentGateway
    participant ES as EmailService

    Client->>OS: Создать заказ
    
    Note over OS: REQ1_1 Проверка наличия
    OS->>OS: Проверить остатки на складе
    
    alt Товар отсутствует
        OS-->>Client: Ошибка
    else Товар в наличии
        Note over OS,PG: REQ1_2 Обработка платежа
        OS->>PG: Запрос на проведение оплаты
        activate PG
        PG-->>OS: Подтверждение оплаты
        deactivate PG
        
        Note over OS,ES: REQ1_3 Отправка уведомления
        OS->>ES: Сформировать письмо
        activate ES
        ES-->>Client: Отправка Email
        deactivate ES
        
        OS-->>Client: Заказ обработан
    end
```

---

## 5. Детальный алгоритм шлюза (Low-Level Activity Diagram)

Детализация работы низкоуровневой логики компонента `PaymentGateway`. Данный алгоритм покрывается тестами класса `TC_Payment_Test`.

```mermaid
flowchart TD
    Start([Вызов метода processPayment]) --> Init[Инициализация сессии транзакции]
    Init --> CheckAntifraud[Запуск скоринга Антифрод]
    
    CheckAntifraud --> Decision{Фрод-рейтинг > 80?}
    Decision -->|Да| RejectFraud[Лог: Подозрение на мошенничество]
    RejectFraud --> SetStatusError[Статус: REJECTED_FRAUD]
    
    Decision -->|Нет| Request3DS{Требуется 3D-Secure?}
    
    Request3DS -->|Да| SendSMS[Отправка СМС / Push]
    SendSMS --> LoopStart[Ожидание кода от пользователя]
    
    LoopStart --> CheckCode{Код верный?}
    CheckCode -->|Нет, попыток < 3| LoopStart
    CheckCode -->|Нет, попытки исчерпаны| SetStatusError
    CheckCode -->|Да| AuthHold[Запрос HOLD на балансе]
    
    Request3DS -->|Нет| AuthHold
    
    AuthHold --> CheckBalance{Успешный HOLD?}
    CheckBalance -->|Нет: Недостаточно средств| SetStatusDeclined[Статус: DECLINED]
    CheckBalance -->|Да| ClearTransaction[Финализация транзакции: CLEAR]
    
    ClearTransaction --> SetStatusSuccess[Статус: SUCCESS]
    
    SetStatusError --> End[Возврат Response объекта клиенту]
    SetStatusDeclined --> End
    SetStatusSuccess --> End
    End --> Finish([Конец выполнения])

    style Decision fill:#f8cecc,stroke:#b85450
    style Request3DS fill:#f8cecc,stroke:#b85450
    style CheckCode fill:#f8cecc,stroke:#b85450
    style CheckBalance fill:#f8cecc,stroke:#b85450
```
