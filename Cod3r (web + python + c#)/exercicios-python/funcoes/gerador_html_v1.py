#!/usr/bin/python3

def tag_bloco(texto, classe='success', inline=False):
    tag = 'span' if inline else 'div'
    return f'<{tag} class="{classe}">{texto}</{tag}>'


def tag_lista(*itens):
    lista = ''.join((f'<li>{item}</li>' for item in itens))
    return f'<ul>{lista}</ul>'


if __name__ == '__main__':
    # Testes (assertions)
    assert tag_bloco('Incluído com sucesso!') == \
        '<div class="success">Incluído com sucesso!</div>'
    assert tag_bloco('Impossível excluir!', 'error') == \
        '<div class="error">Impossível excluir!</div>'
    assert tag_bloco('Agora com span!', inline=True) == \
        '<span class="success">Agora com span!</span>'


    tupla_list_items = ('Ana', 'Mário', 'João')
    print(tag_lista(*tupla_list_items))
    print(tag_bloco(tag_lista(*tupla_list_items), classe="info", inline=False))

    with open('newHtml.html', 'w') as f:
        f.write(tag_bloco(tag_lista(*tupla_list_items), classe="info", inline=False))
    
    