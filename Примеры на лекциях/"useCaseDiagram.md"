graph TD
    %% Актеры
    User((Клиент))
    Manager((Менеджер))

    %% Прецеденты (Use Cases)
    UC1([Создать заказ])
    UC2([Проверить склад])
    UC3([Оплатить заказ])
    UC4([Отправить уведомление])

    %% Связи актеров с прецедентами
    User --> UC1
    User --> UC3
    Manager --> UC2

    %% Внутренние связи системы (Включения)
    UC1 -.->|include| UC2
    UC1 -.->|include| UC3
    UC1 -.->|include| UC4

    %% Стилизация для сходства с Use Case
    style UC1 fill:#f9f,stroke:#333,stroke-width:2px
    style UC2 fill:#bbf,stroke:#333,stroke-width:1px
    style UC3 fill:#bbf,stroke:#333,stroke-width:1px
    style UC4 fill:#bbf,stroke:#333,stroke-width:1px

