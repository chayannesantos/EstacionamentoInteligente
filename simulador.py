
import requests

while(True):
    valor = int(input("Informe um valor: "))
    r = requests.post( "http://estacionalegal.herokuapp.com/upload" , json = {"LDR":valor} )
    print(r.status_code)

    r = requests.get( "http://estacionalegal.herokuapp.com/download" )
    print(r.json())
