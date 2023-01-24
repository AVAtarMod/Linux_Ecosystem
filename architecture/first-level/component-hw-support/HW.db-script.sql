CREATE TABLE "HardwareItemClass"
(
 class_id    serial NOT NULL,
 name        varchar(60) NOT NULL,
 description varchar(220) NOT NULL,
 CONSTRAINT CONSTR_12 PRIMARY KEY ( class_id )
);
CREATE TABLE "HardwareInfo"
(
 hardware_info_id bigserial NOT NULL,
 device_model     varchar(100) NULL,
 CONSTRAINT CONSTR_7 PRIMARY KEY ( hardware_info_id )
);

CREATE TABLE "Product"
(
 product_id bigserial NOT NULL,
 CONSTRAINT CONSTR_15 PRIMARY KEY ( product_id )
);


CREATE TABLE "HardwareItem"
(
 hardware_id      bigserial NOT NULL,
 serial_number    varchar(60) NOT NULL,
 product_id       bigint NOT NULL,
 hardware_info_id bigint NOT NULL,
 class_id         int NOT NULL,
 CONSTRAINT CONSTR_8 PRIMARY KEY ( hardware_id ),
 CONSTRAINT CONSTR_9 FOREIGN KEY ( class_id ) REFERENCES "HardwareItemClass" ( class_id ),
 CONSTRAINT CONSTR_10 FOREIGN KEY ( hardware_info_id ) REFERENCES "HardwareInfo" ( hardware_info_id ),
 CONSTRAINT CONSTR_11 FOREIGN KEY ( product_id ) REFERENCES "Product" ( product_id )
);

CREATE TABLE "Driver"
(
 hardware_id bigint NOT NULL,
 name        varchar(120) NOT NULL,
 description varchar(220) NOT NULL,
 is_active   boolean NOT NULL,
 CONSTRAINT CONSTR_3 PRIMARY KEY ( hardware_id ),
 CONSTRAINT CONSTR_4 FOREIGN KEY ( hardware_id ) REFERENCES "HardwareItem" ( hardware_id )
);
CREATE TABLE "CPUInfo"
(
 product_id   bigint NOT NULL,
 manufacturer varchar(120) NOT NULL,
 model_name   varchar(120) NOT NULL,
 product_name varchar(120) NOT NULL,
 frequency    bigint NOT NULL,
 core_count   int NOT NULL,
 CONSTRAINT CONSTR_1 PRIMARY KEY ( product_id ),
 CONSTRAINT CONSTR_2 FOREIGN KEY ( product_id ) REFERENCES "Product" ( product_id )
);

CREATE INDEX FK_5 ON "CPUInfo"
(
 product_id
);


CREATE INDEX FK_6 ON "Driver"
(
 hardware_id
);

CREATE TABLE "GPUInfo"
(
 product_id   bigint NOT NULL,
 manufacturer varchar(120) NOT NULL,
 model_name   varchar(120) NOT NULL,
 product_name varchar(120) NOT NULL,
 frequency    bigint NOT NULL,
 core_count   int NOT NULL,
 memory_size  bigint NOT NULL,
 CONSTRAINT CONSTR_5 PRIMARY KEY ( product_id ),
 CONSTRAINT CONSTR_6 FOREIGN KEY ( product_id ) REFERENCES "Product" ( product_id )
);

CREATE INDEX FK_1 ON "GPUInfo"
(
 product_id
);

CREATE INDEX FK_2 ON "HardwareItem"
(
 class_id
);


CREATE TABLE "MemoryInfo"
(
 product_id   bigint NOT NULL,
 manufacturer varchar(120) NOT NULL,
 model_name   varchar(120) NOT NULL,
 product_name varchar(120) NOT NULL,
 capacity     bigint NOT NULL,
 technology   int NOT NULL,
 speed        bigint NOT NULL,
 CONSTRAINT CONSTR_13 PRIMARY KEY ( product_id ),
 CONSTRAINT CONSTR_14 FOREIGN KEY ( product_id ) REFERENCES "Product" ( product_id )
);

CREATE INDEX FK_3 ON "MemoryInfo"
(
 product_id
);


CREATE TABLE "StorageInfo"
(
 product_id   bigint NOT NULL,
 manufacturer varchar(120) NOT NULL,
 model_name   varchar(120) NOT NULL,
 product_name varchar(120) NOT NULL,
 capacity     bigint NOT NULL,
 type         int NOT NULL,
 CONSTRAINT CONSTR_16 PRIMARY KEY ( product_id ),
 CONSTRAINT CONSTR_17 FOREIGN KEY ( product_id ) REFERENCES "Product" ( product_id )
);

CREATE INDEX FK_4 ON "StorageInfo"
(
 product_id
);
