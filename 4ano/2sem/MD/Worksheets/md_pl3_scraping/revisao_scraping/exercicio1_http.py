import requests

url = "http://httpbin.org/get"
# TODO: Criar headers realistas (User-Agent, Accept-Language)
# TODO: Fazer requisição GET
# TODO: Verificar status code
# TODO: Imprimir os headers enviados (estão na resposta)

headers = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36",
    "Accept-Language": "pt-BR,pt;q=0.9,en;q=0.8"
}

response = requests.get(url, headers=headers)

if response.status_code == 200:
    print("Sucesso!")
    print("Headers enviados:")
    print(response.json()["headers"])
else:
    print(f"Erro na requisição: {response.status_code}")

