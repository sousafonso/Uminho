# Sensorização e Ambiente

---

## Avaliação
- Trabalho de investigação em grupo e individual
- Trabalho prático em grupo de 4-5 elementos

## Trabalho de investigação
- Investigação em grupo
- Revisão individual de 2 trabalhos de outros grupos
- Apresentação em grupo

Temas:
- Interação pessoa-máquina: recolha de dados de sensores como teclado, rato, microfone, entre outros, promovendo análise comportamental da pessoa
- Atividade física: utilização de sensores de captação de movimento e desenvolver ténicas de controlod e atividades motoras
- Geo-vedações virtuais: recurso a APIs de geofencing para implementação de vedações virtuais em zonas características como salas de aula, lojas, edificios, entre outros
- Variações climáticas: recolha de dados meteorológicos históricos e atuais que permitam realizar inferências e previsões sobre o comportamento do clima
- Conforto ambiente: utilização de sensores de som como microfone ou de temperatura ambiente para definir métricas de conforto ambiente
- Monitorização de acessos: recurso a placas ESP 

## Trabalho prático
- Desenvolvimento de um projeto prático em grupo
- Avaliação por pares

---

## Indíce
- [Ambient Intelligence (AmI)](#ambient-intelligence-ami)
- [Internet of Things (IoT)](#internet-of-things-iot)
- [Internet of People (IoP)](#internet-of-people-iop)
- [Smart Cities](#smart-cities)
- [Data Pyramid (DIKW)](#data-pyramid-dikw)
- [Sensorização](#sensorização)
- [Plataformas de desenvolvimento](#plataformas-de-desenvolvimento)

---
## 1. Ambient Intelligence (AmI)
AmI refere-se a ambientes **sensíveis** e **responsivos** à presença de pessoas, **de forma não intrusiva**. À medida que os dispositivos ficam mais pequenos e integrados, a tecnologia "desaparece" (fica transparente) para o ambiente.

Compõe-se em três pilares:
- **Aquisição de dados:** sensores, câmaras, microfones, entre outros
- **Reasoning:** Data Modeling, Machine Learning, Decision Models para inferir o estado do ambiente e das pessoas
- **Atuação:** atuadores, displays, Notifications, Interactions, Actions, entre outros

---
## 2. Internet of Things (IoT)
Definida como uma **rede aberta e compreensiva de objetos inteligentes** com capacidade de se auto-organizar, partilhar informação, dados e recursos, reagir e agir face a situações e mudanças no ambiente.

---
## 3. Internet of People (IoP)
Uma rede global dinâmica onde **coisas e pessoas comunicam e se compreendem mutuamente**; todos podem **sentir o outro e o mundo, e agir sobre esse conhecimento**, com o objetivo de melhorar a qualidade de vida das pessoas.

---
## 4. Smart Cities
As cidades inteligentes integram tecnologias IoT/AmI/IoP para gerir recursos urbanos de forma eficiente (transporte, energia, comunicação, serviços públicos, etc.).

---
## 5. Data Pyramid (DIKW)
- **Data:** fatos brutos, sem contexto. Ex. "Red, 192.234.235.245.678, v2.0"
- **Information:** dados processados, organizados e estruturados. Ex. "South facing traffic light on corner of Pitt and George Streets has turned red"
- **Knowledge:** informação aplicada, insights e compreensão. Ex. "The traffic light I am driving towards has turned red"
- **Wisdom:** conhecimento aplicado com julgamento e experiência. Ex. "I better stop the car!"

---
## 6. Sensorização
- Um sensor é algo capaz de percecionar fenómenos em observação e traduzir o seu estado.

- Tradicionamente os sensores eram físicos, mas podem ser virtuais (acesso a web APIs, fórmulas matemáticas).

- Atualmente, a data fusion permite inferir ativos virtuais como: Emoções, Bem-estar, Sustentabilidade, Felicidade.

---
## 7. Plataformas de desenvolvimento

### 7.1 Adafruit
- É um cloud service focado em armazenar e recuperar dados de sensores usando feeds.

- Suporta visualização de dados em dashboards em tempo real.

- Permite definir triggers para reagir a dados (ex.: enviar e-mail quando um sensor de temperatura ultrapassa um limite).

- Integração com IFTTT.

- Compatível com Python, Raspberry Pi, micro:bit, Arduino.

### 7.2 Firebase
Plataforma mobile e web da Google com múltiplos serviços:

| Funcionalidade        | Descrição                                                                                             |
| --------------------- | ----------------------------------------------------------------------------------------------------- |
| Authentication        | Gestão de autenticação (Google, Facebook, Email) — evita meses de desenvolvimento próprio             |
| Firestore Database    | Base de dados NoSQL estruturada (coleções e documentos), com melhor desempenho e queries              |
| Realtime Database     | Um grande objeto JSON sincronizado em tempo real                                                      |
| ML Kit                | Integração de Machine Learning (reconhecimento facial, texto, objetos, landmarks) — on-device e cloud |
| Analytics & Dashboard | Monitorização de utilizadores e desempenho da app                                                     |

- Como ligar ao Firebase com Python: Usando firebase_admin, credenciais via Private Key, e a biblioteca firestore.

- Para adicionar dados: NAMEDATABASE.set({ NameField1: ValueField1, NameField2: ValueField2 }).

### 7.3 IFTTT — If This Then That 
- Serviço para criar cadeias de declarações condicionais (applets).

- É acionado por mudanças que ocorrem noutros serviços web e executa uma ação na plataforma destino.

- Disponível como aplicação web, iOS e Android.

- Alternativas: Zapier, Microsoft Power Automate, AutomationAnywhere.

### 7.4 MQTT — Message Queue Telemetry Transport

- Protocolo de conectividade Machine-to-Machine/IoT desenvolvido originalmente pela IBM.

- Modelo publish/subscribe, extremamente simples e lightweight, desenhado para dispositivos com restrições.

- Arquitetura: device/sensor → publica → MQTT broker → subscreve/publica → clientes (smartphone, laptop).

### 7.5 Adafruit IO + IFTTT
Integração prática passo a passo:

1. Criar um feed no Adafruit IO (ex.: SensorFeed).

2. Login no IFTTT e pesquisar pelo serviço Adafruit.

3. Conectar o IFTTT à plataforma Adafruit (autorizar).

4. Criar um novo applet (If This → Then That).

5. Definir o trigger (If This): "Monitor a feed on Adafruit IO" — selecionar o feed, o valor e a relação (ex.: equal to 1).

6. Definir a ação (Then That): "Send a notification from the IFTTT app" — personalizar a mensagem com ingredients (FeedName, FeedValue, TriggerValue, CreatedAt).

7. Rever e confirmar o applet → ativar.

8. Testar: Adicionar um data point com valor 1 ao SensorFeed no Adafruit IO → notificação recebida no smartphone.

9. Se a notificação não chegar, ativar push notifications nas definições do IFTTT.

---
