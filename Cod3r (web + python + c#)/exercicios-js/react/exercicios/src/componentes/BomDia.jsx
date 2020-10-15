import React from 'react'

export default props => (
    [
        <h1 key='h1'>{props.nome}! Você tem {props.idade} anos</h1>,
        <h2 key='h2'>Até breve!</h2>
    ]
)


// export default props => (
//     <React.Fragment>
//         <h1>{props.nome}! Você tem {props.idade} anos</h1>
//         <h2>Até breve!</h2>
//     </React.Fragment>
// )