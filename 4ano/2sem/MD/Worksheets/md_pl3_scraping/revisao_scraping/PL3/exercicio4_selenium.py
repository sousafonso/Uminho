from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.chrome.options import Options
from bs4 import BeautifulSoup
import time
import json
import os

# ============================================================================
# Questão 4.1: Importe o Selenium e configure Chrome options para headless
# ============================================================================

def setup_driver():
    """Configurar Chrome options para headless"""
    options = Options()
    options.add_argument("--headless") # Rodar em modo headless (sem interface gráfica)
    options.add_argument("--no-sandbox") # Necessário para rodar em alguns ambientes (ex: Docker)
    options.add_argument("--disable-dev-shm-usage") # Evitar problemas de memória em ambientes limitados
    
    driver = webdriver.Chrome(options=options)
    return driver


def save_to_json(data, filename):
    """Guardar dados em formato JSON na pasta 'dados'"""
    data_dir = os.path.join(os.path.dirname(__file__), "dados")
    
    if not os.path.exists(data_dir):
        os.makedirs(data_dir)
    
    filepath = os.path.join(data_dir, filename)
    
    with open(filepath, 'w', encoding='utf-8') as f:
        json.dump(data, f, ensure_ascii=False, indent=4)



# ============================================================================
# Questão 4.2: Extração com Selenium puro
# ============================================================================

def extract_quotes_selenium():
    """Extrair citações usando Selenium puro"""
    driver = setup_driver()
    
    try:
        driver.get("http://quotes.toscrape.com/js/")
        
        # Usar WebDriverWait para aguardar carregamento
        WebDriverWait(driver, 10).until(
            EC.presence_of_element_located((By.CLASS_NAME, "quote"))
        )
        
        # Extrair usando Selenium
        quotes = driver.find_elements(By.CLASS_NAME, "quote") # recolhe todos os elementos com a class quote
        
        quotes_data = []
        for quote in quotes: # para cada elemento da lista de citações encontrada
            # Extrair texto, autor e tags
            text = quote.find_element(By.CLASS_NAME, "text").text # extrai o texto da class text que neste caso é a citação
            author = quote.find_element(By.CLASS_NAME, "author").text # extrai o texto da class author que neste caso é o autor da citação
            tags = [tag.text for tag in quote.find_elements(By.CLASS_NAME, "tag")] # armazenas as tags numa lista, para isso percorre as tags encontradas e extrai o texto de cada uma
            
            quotes_data.append({ # adicionar ao dicionário quotes_data os dados extraídos
                "text": text,
                "author": author,
                "tags": tags
            })
        
        return quotes_data
        
    finally:
        driver.quit() # sair do chrome


# ============================================================================
# Questão 4.3: Abordagem híbrida (Selenium + BeautifulSoup)
# ============================================================================

def extract_quotes_hybrid():
    """Extrair citações usando abordagem híbrida (Selenium + BeautifulSoup)"""
    driver = setup_driver()
    
    try:
        driver.get("http://quotes.toscrape.com/js/")
        
        # Aguardar carregamento
        WebDriverWait(driver, 10).until(
            EC.presence_of_element_located((By.CLASS_NAME, "quote"))
        )
        
        # Passar HTML para BeautifulSoup
        html = driver.page_source # obter o código HTML da página carregada pelo Selenium
        soup = BeautifulSoup(html, 'lxml') # criar um objeto BeautifulSoup a partir do código HTML da página carregada pelo Selenium, usando o parser lxml para facilitar a extração dos dados
        
        # Extrair usando BeautifulSoup (mais fácil)
        quotes_data = []
        quotes = soup.find_all("div", class_="quote") # encontrar todos os elementos div com a class quote, que correspondem a cada citação
        
        for quote in quotes:
            text = quote.find("span", class_="text").text # extrair o texto da tag span com a class text, que corresponde à citação
            author = quote.find("small", class_="author").text # extrair o texto da tag small com a class author, que corresponde ao autor da citação
            tags = [tag.text for tag in quote.find_all("a", class_="tag")] # encontrar todas as tags a com a class tag dentro da citação e extrair o texto de cada uma para formar uma lista de tags
            
            quotes_data.append({
                "text": text,
                "author": author,
                "tags": tags
            })
        
        return quotes_data
        
    finally:
        driver.quit()


# ============================================================================
# Questão 4.4: Paginação em sites dinâmicos
# ============================================================================

def extract_quotes_all_pages():
    """Extrair todas as citações de todas as páginas com paginação"""
    driver = setup_driver()
    todas_citacoes = []
    
    try:
        driver.get("http://quotes.toscrape.com/js/")
        
        while True:
            # Aguardar carregamento
            WebDriverWait(driver, 10).until(
                EC.presence_of_element_located((By.CLASS_NAME, "quote"))
            )
            
            # Extrair citações da página atual
            quotes = driver.find_elements(By.CLASS_NAME, "quote")
            
            for quote in quotes:
                text = quote.find_element(By.CLASS_NAME, "text").text
                author = quote.find_element(By.CLASS_NAME, "author").text
                tags = [tag.text for tag in quote.find_elements(By.CLASS_NAME, "tag")]
                
                todas_citacoes.append({
                    "text": text,
                    "author": author,
                    "tags": tags
                })
            
            # Procurar botão "Next"
            try:
                next_button = driver.find_element(By.CSS_SELECTOR, "li.next > a") # encontrar o botão "Next" usando um seletor CSS que procura um elemento li com a classe next que contém um link (a)
                next_button.click() # clicar no botão "Next" para carregar a próxima página
                time.sleep(2)  # Aguardar carregamento
            except:
                print("Não há mais páginas")
                break
                
    finally:
        driver.quit()
    
    print(f"Total de citações: {len(todas_citacoes)}")
    return todas_citacoes 

if __name__ == "__main__":
    print("=" * 70)
    print("Questão 4.2: Extração com Selenium puro")
    print("=" * 70)
    quotes_selenium = extract_quotes_selenium()
    for quote in quotes_selenium[:3]:  # Mostrar primeiras 3
        print(f"\n{quote['text']}")
        print(f"- {quote['author']}")
        print(f"Tags: {', '.join(quote['tags'])}")
    
    # Guardar dados
    save_to_json(quotes_selenium, "questao_4_2_selenium_puro.json")
    
    print("\n" + "=" * 70)
    print("Questão 4.3: Abordagem híbrida (Selenium + BeautifulSoup)")
    print("=" * 70)
    quotes_hybrid = extract_quotes_hybrid()
    for quote in quotes_hybrid[:3]:  # Mostrar primeiras 3
        print(f"\n{quote['text']}")
        print(f"- {quote['author']}")
        print(f"Tags: {', '.join(quote['tags'])}")
    
    # Guardar dados
    save_to_json(quotes_hybrid, "questao_4_3_hibrida.json")
    
    print("\n" + "=" * 70)
    print("Questão 4.4: Paginação em sites dinâmicos")
    print("=" * 70)
    todas_citacoes = extract_quotes_all_pages()
    print(f"\nPrimeira citação de todas as páginas:")
    print(f"{todas_citacoes[0]['text']}")
    print(f"- {todas_citacoes[0]['author']}")
    
    # Guardar dados
    save_to_json(todas_citacoes, "questao_4_4_paginacao.json")
    
    print("\n" + "=" * 70)
    print("Todos os dados foram guardados na pasta 'dados'")
    print("=" * 70)
