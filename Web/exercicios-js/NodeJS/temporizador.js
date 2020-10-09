const schedule = require('node-schedule')

const tarefa1 = schedule.scheduleJob('*/5 * 14 * * 2', function(){
    // essa string significa: que vai executar de 5 em 5 segundos, às 12 horas
    // ignorar o dia, o mês numa terça feira (domingo é 0, segunda é 1,...)
    console.log('Executando tarefa1', new Date().getSeconds())
})

setTimeout(function () {
    tarefa1.cancel()
    console.log('Cancelando tarefa 1!')
}, 20000)

const regra = new schedule.RecurrenceRule()
regra.dayOfWeek = [new schedule.Range(1,5)]
regra.hour = 12
regra.second = 30

tarefa2 = schedule.scheduleJob(regra, function(){
    console.log('Executando Tarefa 2!', new Date().getSeconds)
})