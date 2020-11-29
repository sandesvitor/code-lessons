CREATE TABLE IF NOT EXISTS cidades(
    id NOT UNSIGNED NOT NULL,
    estado_id int unsigned NOT NULL,
    area DECIMAL(10,2),
    PRIMARY KEY (id),
    FOREIGN KEY (estado_id) REFERENCE estados (id)
);