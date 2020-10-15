function fatorial(num) {
    if (num == 0) {
        return 1
    } else {
        num * fatorial(num - 1)
    }
}

console.log(fatorial(0))
