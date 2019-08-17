# Estacionamento Inteligente

**Este projeto foi desenvolvido por Chayanne Barbosa dos Santos e Elayne Cristina Donato na disciplina de Técnicas de Programação (2019.1) tendo como base as aulas ministradas pelo professor PATRIC LACOUTH.**

![Intro](https://github.com/chayannesantos/EstacionamentoInteligente/blob/master/Imagens%20do%20Manual/Estacionamento.jpg)

## Introdução

A sinalização no trânsito é de extrema importância para garantir que o fluxo de veículos ocorra de forma segura, sem que haja grandes problemas. E em estacionamentos a relevância não é diferente. A grande demanda de vagas em estacionamentos, vem causando alguns transtornos aos motoristas, pensando nisso foi criado o projeto Estacionamento Inteligente.

O sistema de estacionamento inteligente começou a ser utilizado há poucos anos no Brasil e já está disponível em algumas cidades brasileiras .Esse sistema  vem sendo utilizado como uma boa solução para a mobilidade urbana, pois tornou-se um facilitador na busca por vagas, assim o condutor pode, através das cores dos leds, saber onde há vagas disponíveis.

## Manual do Usuário

### Interface da Guarita

A interface da guarita do estacionamento é composta por três menus conforme mostra a figura a seguir:
 
Na figura, podemos destacar os menus mencionados:

![Abas](https://github.com/chayannesantos/EstacionamentoInteligente/blob/master/Imagens%20do%20Manual/Imagem01.jpg)

•	Menu Conexão: Responsável por estabelecer os dados de conexão com o microcontrolador (Arduino Uno R3).

•	Menu Vagas: Nessa opção o proprietário poderá acompanhar a quantidade de vagas disponíveis e se o estacionamento está lotado. Além disso poderá verificar individualmente quais vagas estão disponíveis e quais estão ocupadas por meio do status.

•	Menu Acesso: Neste menu o proprietário poderá abrir a cancela para o automóvel entrar ou sair do estacionamento através de dois botões. Além disso, poderá acompanhar o status da cancela, se a mesma está aberta ou fechada.

### Estabelecendo a conexão

Estando no menu Conexão, inicialmente, o status da conexão estará mostrando “Desconectado”.

![Desconectado](https://github.com/chayannesantos/EstacionamentoInteligente/blob/master/Imagens%20do%20Manual/Imagem02.jpg)

Para estabelecer uma comunicação com o Arduino, é necessário escolher a porta de comunicação em que o microcontrolador foi conectado. 

![PortaSerial](https://github.com/chayannesantos/EstacionamentoInteligente/blob/master/Imagens%20do%20Manual/Imagem03.jpg)

Logo após devemos escolher a velocidade de comunicação, como podemos ver na figura abaixo. Por padrão, a velocidade escolhida deverá ser a mesma utilizada no arduino de 115200. 

![Velocidade](https://github.com/chayannesantos/EstacionamentoInteligente/blob/master/Imagens%20do%20Manual/Imagem04.jpg)

Uma vez que os dados de conexão foram estabelecidos, devemos acionar o botão abrir. 

![Abrir](https://github.com/chayannesantos/EstacionamentoInteligente/blob/master/Imagens%20do%20Manual/Imagem05.jpg)

Se tudo ocorrer como previsto, o Status da conexão mudará para “Conectado”.      

![Conectado](https://github.com/chayannesantos/EstacionamentoInteligente/blob/master/Imagens%20do%20Manual/Imagem06.jpg)

### Estabelecendo o controle de vagas

Como a conexão foi estabelecida com sucesso, inicialmente no layout do menu vagas a quantidade será de 3 e os status de cada vaga será disponível, pois ainda não entrou nenhum carro no estacionamento. 

![Vagas](https://github.com/chayannesantos/EstacionamentoInteligente/blob/master/Imagens%20do%20Manual/Imagem07.jpg)

### Como faremos para entrar ou sair do estacionamento? 

Muito simples! Basta ir no menu Acesso e clicar no botão “Entrar”.  Se houver disponibilidade de vagas o status da “Cancela Automática” irá sinalizar que a cancela foi “Aberta”. Ao clicar no botão “Sair” o processo é análogo.

![Acesso](https://github.com/chayannesantos/EstacionamentoInteligente/blob/master/Imagens%20do%20Manual/Imagem08.jpg)

Logo após a passagem do carro o campo “Cancela Automática” indicará que a cancela foi fechada. 

![CancelaFechada](https://github.com/chayannesantos/EstacionamentoInteligente/blob/master/Imagens%20do%20Manual/Imagem09.jpg)

### Como faremos para verificar se a vaga foi realmente ocupada?

Basta ir no menu Vagas e verificar o status. No exemplo a seguir o cliente ocupou a vaga 03 e automaticamente o status mudou para “Ocupado”. Além disso, é possível ver a atualização da quantidade de vagas no campo “Quant. Vagas Disponíveis”. 

![VagaOcupado](https://github.com/chayannesantos/EstacionamentoInteligente/blob/master/Imagens%20do%20Manual/Imagem10.jpg)

### E como podemos verificar se ainda há vagas disponíveis? 

Olha só que legal! É análoga a explicação anterior, basta acessar o menu Vagas para acompanhar o status. Porém se todas as vagas estiverem preenchidas, automaticamente o status de cada vaga ficará como “Ocupado” e aparecerá uma mensagem de “Estacionamento Lotado”, onde antes informava a quantidade de vagas disponíveis no campo “Quant. Vagas Disponíveis”. 

![EstacionamentoLotado](https://github.com/chayannesantos/EstacionamentoInteligente/blob/master/Imagens%20do%20Manual/Imagem11.jpg)

## Interface Web

O usuário também pode ter acesso a nossa interface WEB, através de qualquer dispositivo que possua acesso a Internet. Para ter o acesso basta acessar o link:
http://estacionalegal.herokuapp.com 

![Site](https://github.com/chayannesantos/EstacionamentoInteligente/blob/master/Imagens%20do%20Manual/Interface%20Web.jpg)

Através dela podemos abrir ou fechar a cancela, saber a quantidade de carros no estacionamento, bem como as vagas disponíveis.
Para a realização do site, utilizamos através de rotas o Json(JavaScript Object Notation), assim podemos comutar os dados entre o site, arduino e o QT creator.

### Como é feita a atualização dos dados no Java Script?

Para executar a atualização, fazemos o uso do conn.emit que a cada dado novo modifica a informação. 

![CodigoSite1](https://github.com/chayannesantos/EstacionamentoInteligente/blob/master/Imagens%20do%20Manual/atualiza.jpg)

### Como podemos emitir os sinais no app.py?

Para a comunicação é preciso criar as rotas, assim como os sinais que serão emitidos do site para o circuito. Fizemos o uso do socketio.on para que esse sinal fosse emitido.

![CodigoSite2](https://github.com/chayannesantos/EstacionamentoInteligente/blob/master/Imagens%20do%20Manual/rotas.jpg)

## Entendendo a comunicação

Para estabelecer a comunicação usamos o JSON. O arduino e o QT Creator se comunicam entre si e enviam as informações para a interface o web.
![Comunicacao](https://github.com/chayannesantos/EstacionamentoInteligente/blob/master/Imagens%20do%20Manual/Comunica%C3%A7%C3%A3o.jpg)

## Protótipo

O desenvolvimento lógico do protótipo contém três segmentos básicos:

  • Arduino: Que fará o controle dos dispositivos eletrônicos. Na figura abaixo podemos ver a conexão destes dispositivos utilizados no protótipo.
  
  • A Interface do Estabelecimento: Desenvolvido através do QT Creator.
  
  • A Interface do Cliente: Página WEB que poderá ser acessada pelo usuário.

![Protótipo](https://github.com/chayannesantos/EstacionamentoInteligente/blob/master/Imagens%20do%20Manual/Circuito_Tinkercad.jpg)

