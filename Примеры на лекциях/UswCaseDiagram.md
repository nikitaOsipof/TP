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
        OS-->>Client: Ошибка Товара нет в наличии
    else Товар в наличии
        Note over OS,PG: REQ1_2 Обработка платежа
        OS->>PG: Запрос на проведение оплаты
        activate PG
        PG-->>OS: Подтверждение оплаты Успешно
        deactivate PG
        
        Note over OS,ES: REQ1_3 Отправка уведомления
        OS->>ES: Сформировать письмо клиенту
        activate ES
        ES-->>Client: Email Ваш заказ успешно оформлен
        deactivate ES
        
        OS-->>Client: Заказ успешно обработан
    end
