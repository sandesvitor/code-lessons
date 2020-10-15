function f1() {
    alert('Pare de Clicar na Tela por favor')
}

document.getElementsByTagName('body')[0].onclick = f1

f1()