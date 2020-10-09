function funcaoQuad(a, b, c) {
    delta = (Math.sqrt(b**2 - 4*a*c))

    if (delta >= 0) {
        x1 = (-b + delta)/(2*a)
        x2 = (-b - delta)/(2*a)
        console.log(`Valores de x1 e x2: ${[x1, x2]}`)
    }
    else {
        console.log('Delta menor do que zero!')
    }
}

funcaoQuad(3, -5, 0)