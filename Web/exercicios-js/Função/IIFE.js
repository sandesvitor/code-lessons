// IIEF - Immediatly Invoked Function Expression

(function (){
    console.log('Será executado na hora!')
    console.log('Foge do escopo mais abrangente!')
})()

// (function(){...}) - assim foge do escopo global
// "var", "const" e "let" estarão ofra do escopo global.