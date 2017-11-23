/*Universidade Federal do Rio de Janeiro
  Departamento de Engenharia Eletrônica e de Computação
  Sistemas Operacionais Pedro Henrique Cruz Caminha
  Brenno Rodrigues de Carvalho da Silva
*/


// Wire - Version: Latest 
#include <Wire.h>
// SoftwareSerial - Version: Latest 
#include <SoftwareSerial.h>
//Create a new software  serial
SoftwareSerial bluetooth(2, 3); //TX, RX (Bluetooth)

void setup() {
  bluetooth.begin(9600);
  Wire.begin();// Definindo como Master o gerenciador bluetooth
}

void loop() {
unsigned char  i2c_adress = 0x1;//Contador de endereço
unsigned char  i2c_slaves = 0x71;//quantidade máxima de slaves 
char key;//chave que verificará se o Slave deseja enviar ou não alguma informação
  for(i2c_adress; i2c_adress<i2c_slaves;i2c_adress++){
    Wire.requestFrom((int)i2c_adress,1);//requisitando valor da chave para verificar se algo deseja ser enviado;
    while (Wire.available()) { // slave may send less than requested
      key = Wire.read(); // recebe um byte como char
    }
    if(!key){//checa se a chave é diferente de 0;
      Wire.beginTransmission(i2c_adress);//começa transmissão de dados
      bluetooth.println("Slave: ");
      bluetooth.println(i2c_adress);
      bluetooth.println("Data: ");
      while (Wire.available()) { // slave may send less than requested
        char c = Wire.read(); // receive a byte as character
        bluetooth.println(c);
      }
      Wire.endTransmission(i2c_adress);//encerra transmissão de dados
      delay(500);
    }
    delay(500);
  }  
}
