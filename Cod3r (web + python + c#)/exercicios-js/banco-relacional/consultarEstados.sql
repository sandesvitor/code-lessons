-- Consultando a tabela estados:

-- Seleciona tudo da TABLE estados
select 
    estados.* 
from webmoderno.estados

-- Selecionando os estados de população maios que 3 mi ordenando em ORDEM DECRESCENTE:
SELECT 
    estados.* 
FROM webmoderno.estados 
WHERE estados.populacao >= 3 ORDER BY populacao desc;