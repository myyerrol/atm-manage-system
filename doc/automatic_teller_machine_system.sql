create database automatic_teller_machine_system;

use automatic_teller_machine_system;

create table user_information(
    user_name  varchar(15) not null,
    user_age   varchar(5)  not null,
    user_sex   varchar(5)  not null,
    user_phone varchar(15) not null,
    card_id    varchar(10) not null,
    primary key(user_name)
)
engine = InnoDB
character set utf8 collate utf8_general_ci;

create table card_information(
    card_id    varchar(10) not null,
    card_pwd   varchar(10) not null,
    card_money int(10)     not null,
    primary key(card_id)
)
engine = InnoDB
character set utf8 collate utf8_general_ci;

insert into user_information(
user_name, user_age, user_sex, user_phone, card_id) values
('刘一', '18', '男', '13234329374', '000000'),
('陈二', '20', '女', '18364593942', '000001'),
('张三', '15', '男', '19388423225', '000002'),
('李四', '25', '男', '13849239862', '000003'),
('王五', '35', '男', '18829389283', '000004');

insert into card_information(
card_id, card_pwd, card_money) values
('000000', '100000', 5000),
('000001', '100001', 15000),
('000002', '100002', 2000),
('000003', '100003', 100),
('000004', '100004', 4500);
