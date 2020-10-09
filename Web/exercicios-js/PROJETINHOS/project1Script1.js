let x = 'First alert'
alert(x)

// h1 element virtually created by javascript
let my_element = document.createElement('h1');
let my_span = document.createElement('span');

my_span.innerText = 'Snades Book';
my_element.appendChild(my_span);

document.body.appendChild(my_element);

my_element.classList.add('texto_principal');