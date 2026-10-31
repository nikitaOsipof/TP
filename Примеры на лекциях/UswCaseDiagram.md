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

    UC1 -. include .-> UC2
    UC1 -. include .-> UC3
    UC1 -. include .-> UC4

    style UC1 fill:#f9f,stroke:#333,stroke-width:2px
    style UC2 fill:#bbf,stroke:#333,stroke-width:1px
    style UC3 fill:#bbf,stroke:#333,stroke-width:1px
    style UC4 fill:#bbf,stroke:#333,stroke-width:1px
