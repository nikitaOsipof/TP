# Материалы курса "Технологии программирования"
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
