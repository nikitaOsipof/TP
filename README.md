# Архитектурное описание системы обработки заказов (Order Processing System)

Данный документ содержит техническую спецификацию и архитектурные диаграммы системы. Все диаграммы интерактивны и рендерятся нативно средствами GitHub.

---

## 1. Спецификация требований (Requirement Diagram)

```mermaid
flowchart TD
    REQ1["<b>REQ1: Обработка заказа</b><br/>Система должна обрабатывать заказ"]
    REQ1_1["<b>REQ1.1: Inventory</b><br/>Проверить наличие товара<br/>Риск: medium"]
    REQ1_2["<b>REQ1.2: Payment</b><br/>Обрабатывать платеж<br/>Риск: high"]
    REQ1_3["<b>REQ1.3: Notification</b><br/>Отправлять уведомление<br/>Риск: low"]

    OrderService["«Class»<br/><b>OrderService</b>"]
    PaymentGateway["«Class»<br/><b>PaymentGateway</b>"]
    EmailService["«Class»<br/><b>EmailService</b>"]
    TC_Payment_Test["«TestCase»<br/><b>TC_Payment_Test</b>"]

    REQ1 --> REQ1_1
    REQ1 --> REQ1_2
    REQ1 --> REQ1_3

    OrderService -.->|satisfies| REQ1_1
    PaymentGateway -.->|satisfies| REQ1_2
    EmailService -.->|satisfies| REQ1_3
    TC_Payment_Test -.->|verifies| REQ1_2

    style REQ1 fill:#f9f,stroke:#333
    style OrderService fill:#bbf,stroke:#333
    style PaymentGateway fill:#bbf,stroke:#333
    style EmailService fill:#bbf,stroke:#333
    style TC_Payment_Test fill:#bfb,stroke:#333
```

---

## 2. Границы системы и прецеденты (Use Case Diagram)

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

    style UC1 fill:#f9f,stroke:#333
    style UC2 fill:#bbf,stroke:#333
    style UC3 fill:#bbf,stroke:#333
    style UC4 fill:#bbf,stroke:#333
```

---

## 3. Бизнес-процесс обработки платежа (Activity Diagram)

```mermaid
flowchart TD
    A([Начало: Оплата]) --> B[Ввод данных карты]
    B --> C{Проверка полей}
    C -->|Данные некорректны| B
    C -->|Данные верны| E[Запрос в Банк]
    E --> G{Достаточно средств?}
    G -->|Нет| H[Отказ банка]
    G -->|Да| I[Списание средств]
    H --> L([Конец: Отклонено])
    I --> M([Конец: Оплачено])
```

---

## 4. Динамическое взаимодействие компонентов (Sequence Diagram)

```mermaid
sequenceDiagram
    actor Client as Клиент
    participant OS as OrderService
    participant PG as PaymentGateway

    Client->>OS: Создать заказ
    OS->>OS: Проверить остатки
    OS->>PG: Запрос на оплату
    PG-->>OS: Успешно
    OS-->>Client: Заказ обработан
```

---

## 5. Жизненный цикл заказа (State Machine Diagram)

Диаграмма состояний описывает внутреннее поведение сущности «Заказ», правила смены статусов и возможные триггеры переходов.

```mermaid
stateDiagram-v2
    [*] --> Создан : Клиент отправляет корзину

    state Создан {
        [*] --> ОжидаетОплаты
        ОжидаетОплаты --> Отменен : Таймаут 30 мин / Отмена клиентом
        ОжидаетОплаты --> Оплачен : Успешный платеж (REQ1.2)
    }

    state Оплачен {
        [*] --> СборкаНаСкладе
        СборкаНаСкладе --> ПереданВДоставку : Передан курьеру
    }

    ПереданВДоставку --> Доставлен : Успешное вручение
    ПереданВДоставку --> Возврат : Клиент отказался при получении

    Отменен --> [*]
    Доставлен --> [*]
    Возврат --> Создан : Повторный круг (опционально)
```
## 6. Метод валидации номера банковской карты по алгоритму Луна (Luhn Algorithm) (Activity Diagram)
'''mermaid
flowchart TD
    Start([Вход: string cardNumber]) --> Clear[1. Удалить пробелы и дефисы из строки]
    Clear --> CheckDigits{2. Строка состоит только из цифр?}
    
    CheckDigits -->|Нет| RetFalse1[Возврат: false]
    
    CheckDigits -->|Да| InitVars[3. Инициализировать variables:<br/>int sum = 0<br/>bool alternate = false]
    InitVars --> LoopStart[4. Цикл с конца строки:<br/>int i = cardNumber.Length - 1]
    
    LoopStart --> LoopCheck{i >= 0 ?}
    
    LoopCheck -->|Нет / Цикл завершен| FinalCheck{5. sum % 10 == 0 ?}
    FinalCheck -->|Да| RetTrue([Возврат: true])
    FinalCheck -->|Нет| RetFalse2([Возврат: false])
    
    LoopCheck -->|Да / Итерация| GetDigit[6. Перевести символ в цифру:<br/>int n = cardNumber[i] - '0']
    GetDigit --> CheckAlt{7. Переменная alternate == true?}
    
    CheckAlt -->|Да| Multiply[8. Умножить цифру на 2:<br/>n = n * 2]
    Multiply --> CheckNine{9. n > 9 ?}
    CheckNine -->|Да| Subtract[10. n = n - 9]
    CheckNine -->|Нет| ToggleAlt
    Subtract --> ToggleAlt
    
    CheckAlt -->|Нет| ToggleAlt[11. Прибавить к общей сумме:<br/>sum = sum + n]
    ToggleAlt --> NextIter[12. Инвертировать флаг:<br/>alternate = !alternate]
    
    NextIter --> Decrement[13. i = i - 1]
    Decrement --> LoopCheck

    style CheckDigits fill:#fff2cc,stroke:#d6b656
    style LoopCheck fill:#fff2cc,stroke:#d6b656
    style CheckAlt fill:#fff2cc,stroke:#d6b656
    style CheckNine fill:#fff2cc,stroke:#d6b656
    style FinalCheck fill:#fff2cc,stroke:#d6b656
    style RetFalse1 fill:#f8cecc,stroke:#b85450
    style RetFalse2 fill:#f8cecc,stroke:#b85450
    style RetTrue fill:#d5e8d4,stroke:#82b366
'''
