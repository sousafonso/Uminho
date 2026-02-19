import requests
from bs4 import BeautifulSoup

url = "http://quotes.toscrape.com"
response = requests.get(url, headers={'User-Agent': 'Mozilla/5.0'})
soup = BeautifulSoup(response.text, 'lxml')

#Print to a file(all the prints above) - optional
with open("dados/exercicios_2_output.txt", "w") as f:
    # Redirect print statements to the file
    import sys
    original_stdout = sys.stdout
    sys.stdout = f

    #######################################################################
    # Questão 2.1. Extração com find() e find_all().
    #######################################################################

    # Usando find_all(), extraia:
    # - Todas as tags (a.tag)

    # Exemplo dos slides - soup.find_all('div', class_='produto’) -> Find ALL divs with class “product”

    # - Todas as citações (div.quote)
    soup.find_all('div', class_='quote') 
    print("Todas as citações:\n")
    for quote in soup.find_all('div', class_='quote'):
        quote_text = quote.find('span', class_='text')
        if quote_text:
            print(quote_text.text)

    # - Todos os autores (small.author)
    soup.find_all('small', class_='author')  
    print("\n\nTodos os autores:")
    for author in soup.find_all('small', class_='author'):
        print(author.text)

    # - Todas as tags (a.tag)
    soup.find_all('a', class_='tag')  
    print("\n\nTodas as tags:")
    for tag in soup.find_all('a', class_='tag'):
        print(tag.text)

    # Usando find(), extraia:

    # Exemplos dos slides - soup.find('div', class_='produto’) -> Find the FIRST div with class “product”

    # - O primeiro autor da página
    print("\n\nO primeiro autor da página:")
    first_author = soup.find('small', class_='author')
    print(first_author.text)

    # - A primeira citação
    first_quote = soup.find('div', class_='quote')
    print("\n\nA primeira citação:")
    first_quote_text = first_quote.find('span', class_='text')
    if first_quote_text:
        print(first_quote_text.text)

    # - O link "Next" (se existir)
    print("\n\nO link 'Next' (se existir):")
    next_link = soup.find('li', class_='next')
    if next_link:
        next_href = next_link.find('a')
        if next_href:
            print(next_href.get('href'))


    #######################################################################
    #Questão 2.2. Extração com select() e select_one().
    #######################################################################

    # TODO: Refaça as extrações anteriores utilizando seletores CSS
    # o select() para múltiplos elementos
    # o select_one() para elementos únicos

    print("\n\n\nParte 2: Usando seletores CSS:\n")

    # - Todas as tags (a.tag)
    soup.select('a.tag')  
    print("\n\nTodas as tags:")
    for tag in soup.select('a.tag'):
        print(tag.text)

    # - Todas as citações (div.quote)
    soup.select('div.quote')
    print("\n\nTodas as citações:")
    for quote in soup.select('div.quote span.text'):
        print(quote.text)

    # - Todos os autores (small.author)
    soup.select('small.author')
    print("\n\nTodos os autores:")
    for author in soup.select('small.author'):
        print(author.text)

    # - O primeiro autor da página
    soup.select_one('small.author')
    print("\n\nO primeiro autor da página:")
    first_author = soup.select_one('small.author')
    print(first_author.text)

    # - A primeira citação
    soup.select_one('div.quote')
    print("\n\nA primeira citação:")
    first_quote_text = soup.select_one('div.quote span.text')
    if first_quote_text:
        print(first_quote_text.text)

    # - O link "Next" (se existir)
    soup.select_one('li.next')
    print("\n\nO link 'Next' (se existir):")
    next_link = soup.select_one('li.next a')
    if next_link:
        print(next_link.get('href'))

    # Utilize seletores hierárquicos para extrair:

    # Todas as tags dentro de cada citação
    print("\n\nTodas as tags dentro de cada citação:")
    for quote in soup.select('div.quote'):
        tags = quote.select('a.tag')
        print(tags)

    print("\n\nO autor da primeira citação, usando hierarquia CSS:")
    first_quote_author = soup.select_one('div.quote small.author')
    print(first_quote_author.text)

    #######################################################################
    #Questão 2.3. Extração de atributos. Para cada citação, extraia também:
    #######################################################################

    # O valor do atributo href do link About do autor
    print("\n\nValor do atributo href do link About do autor:")   
    for quote in soup.select('div.quote'):
        about_link = quote.select_one('a[href*="/author/"]')
        if about_link:
            print(f"Atributo href do link About do autor: {about_link.get('href')}")

    #O número total de tags associadas à citação
    print("\n\nNúmero total de tags associadas à citação:")
    for quote in soup.select('div.quote'):
        tags = quote.select('a.tag')
        print(f"Número total de tags associadas à citação: {len(tags)}")

    #O conteúdo do atributo class da citação
    print("\n\nConteúdo do atributo class de cada citação:")
    for quote in soup.select('div.quote'):
        classes = quote.get('class')
        print(f"Conteúdo do atributo class da citação: {classes}")


    # Restore original stdout
    sys.stdout = original_stdout