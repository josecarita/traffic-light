//formato de semaforos
//orden_semaforo = [rojo,verde,amarillo]
//los elementos seran numeros de pines

//formato de semaforo peatonal
//orden_peatonales = [rojo,verde]
//los elementos seran numeros de pines

//formato de posicion de semaforos
//semaforos[4][3]={N-S,S-N,E-O,O-E}
//peatonales[4][2]={E-O,O-E,N-S,S-N}
int semaforos[4][3]={{22,23,24},{27,28,29},{32,33,34},{37,38,39}};
int peatonales[4][2]={{25,26},{30,31},{35,36},{40,41}};

int tiempo_rojo = 20*1000;
int tiempo_verde = tiempo_rojo*0.7;
int tiempo_amarillo = tiempo_rojo*0.3;

void setup() {
for (int a=22;a<54;a++){
  pinMode(a, OUTPUT);
  digitalWrite(a,LOW);
  }
  
Serial.begin(9600);
}

void loop() {
  while (Serial.available()>0){
    String str = Serial.readString();
    tiempo_rojo = str.toInt()*1000;
    tiempo_verde = tiempo_rojo*0.7;
    tiempo_amarillo = tiempo_rojo*0.3;
  }

  Serial.print("Tiempo de luz roja: ");
  Serial.print(tiempo_rojo/1000);
  Serial.println(" segundos.");
  etapa_1();
  etapa_2();

}
/*
funcion1()
semaforo1y2 prden roja.....
semarofo3y4 prender verde....
peatonal1y2 prenden verde....
peatonal3y4 prenden roja....
  tiempo verde..............
semaforo 3y4 apagar verde.......
semaforo 3y4 prender amarillo.....
            
  tiempo amarillo................
semaforo1y2 apagar roja.........
semarofo3y4 apagar amarillo......
peatonal1y2 apaga verde.........
peatonal3y4 apaga roja...........


funcion2()
semaforo3y4 prden roja......
semarofo1y2 prender verde.....
peatonal3y4 prenden verde....
peatonal1y2 prenden roja......
  tiempo verde.....
semaforo1y2 apagar verde.......
semaforo1y2 prender amarillo........
            
  tiempo amarillo..........
semaforo3y4 apagar roja...........
semarofo1y2 apagar amarillo.....
peatonal3y4 apaga verde.......
peatonal1y2 apaga roja......
*/
void etapa_1 (){
  
  //prender luz roja SN NS
  for (int i=0; i<2;i++){
    digitalWrite(semaforos[i][0],HIGH); 
    Serial.println(semaforos[i][0]);
    }
  Serial.println("rojo SN NS");

  //prender luz verde EO OE
  for (int i=2; i<4;i++){
    digitalWrite(semaforos[i][1],HIGH); 
    Serial.println(semaforos[i][1]);
    }
  Serial.println("verde EO OE");

  //prender luz verde peatonal EO OE
  for (int i=0; i<2;i++){
    digitalWrite(peatonales[i][1],HIGH); 
    Serial.println(peatonales[i][1]);
    }
  Serial.println("peatonales verde EO OE");

  //prender luz roja peatonal SN NS
  for (int i=2; i<4;i++){
    digitalWrite(peatonales[i][0],HIGH); 
    Serial.println(peatonales[i][0]);
    }
  Serial.println("peatonales rojo SN NS");

  ///////////////////////////////////////////////
  delay(tiempo_verde);
  Serial.println("/////////////////////////////////////");
  ///////////////////////////////////////////////
  
  //APAGAR luz verde EO OE
  for (int i=2; i<4;i++){
    digitalWrite(semaforos[i][1],LOW); 
    Serial.println(semaforos[i][1]);
    }
  Serial.println("apagado verde EO OE");

  //prender amarillo EO OE
  for (int i=2; i<4;i++){
    digitalWrite(semaforos[i][2],HIGH); 
    Serial.println(semaforos[i][2]);
    }
  Serial.println("amarillo EO OE");
  
  /////////////////////////////////////////////////
  delay(tiempo_amarillo);
  Serial.println("/////////////////////////////////////");
  ////////////////////////////////////////////////

  //apagar amarillo EO OE
  for (int i=2; i<4;i++){
    digitalWrite(semaforos[i][2],LOW); 
    Serial.println(semaforos[i][2]);
    }
  Serial.println("apagar amarillo EO OE");
  
  //apagar luz roja SN NS
  for (int i=0; i<2;i++){
    digitalWrite(semaforos[i][0],LOW);
    Serial.println(semaforos[i][0]);
    }
  Serial.println("apagado roja SN NS");

  //apagar luz verde peatonal EO OE
  for (int i=0; i<2;i++){
    digitalWrite(peatonales[i][1],LOW); 
    Serial.println(peatonales[i][1]);
    }
  Serial.println("apagado peatonales verde EO OE");

  //apagar luz roja peatonal SN NS
  for (int i=2; i<4;i++){
    digitalWrite(peatonales[i][0],LOW); 
    Serial.println(peatonales[i][0]);
    }
  Serial.println("apagar peatonales rojo SN NS");
  
}

void etapa_2() {
  
//prender luz roja OE EO
  for (int i=2; i<4;i++){
    digitalWrite(semaforos[i][0],HIGH); 
    Serial.println(semaforos[i][0]);
    }
  Serial.println("rojo EO OE");

  //prender luz verde SN NS
  for (int i=0; i<2;i++){
    digitalWrite(semaforos[i][1],HIGH); 
    Serial.println(semaforos[i][1]);
    }
  Serial.println("verde SN NS");

  //prender luz verde peatonal SN NS
  for (int i=2; i<4;i++){
    digitalWrite(peatonales[i][1],HIGH); 
    Serial.println(peatonales[i][1]);
    }
  Serial.println("peatonales verde SN NS");

  //prender luz roja peatonal OE EO
  for (int i=0; i<2;i++){
    digitalWrite(peatonales[i][0],HIGH); 
    Serial.println(peatonales[i][0]);
    }
  Serial.println("peatonales rojo EO OE");

  ///////////////////////////////////////////////
  delay(tiempo_verde);
  Serial.println("/////////////////////////////////////");
  ///////////////////////////////////////////////
  
  //APAGAR luz verde SN NS
  for (int i=0; i<2;i++){
    digitalWrite(semaforos[i][1],LOW); 
    Serial.println(semaforos[i][1]);
    }
  Serial.println("apagado verde SN NS");

  //prender amarillo SN NS
  for (int i=0; i<2;i++){
    digitalWrite(semaforos[i][2],HIGH); 
    Serial.println(semaforos[i][2]);
    }
  Serial.println("amarillo SN NS");
  
  /////////////////////////////////////////////////
  delay(tiempo_amarillo);
  Serial.println("/////////////////////////////////////");
  ////////////////////////////////////////////////

  //apagar amarillo SN NS
  for (int i=0; i<2;i++){
    digitalWrite(semaforos[i][2],LOW); 
    Serial.println(semaforos[i][2]);
    }
  Serial.println("apagar amarillo SN NS");
  
  //apagar luz roja EO OE
  for (int i=2; i<4;i++){
    digitalWrite(semaforos[i][0],LOW);
    Serial.println(semaforos[i][0]);
    }
  Serial.println("apagado roja OE EO");

  //apagar luz verde peatonal SN NS
  for (int i=2; i<4;i++){
    digitalWrite(peatonales[i][1],LOW); 
    Serial.println(peatonales[i][1]);
    }
  Serial.println("apagado peatonales verde SN NS");

  //apagar luz roja peatonal OE EO
  for (int i=0; i<2;i++){
    digitalWrite(peatonales[i][0],LOW); 
    Serial.println(peatonales[i][0]);
    }
  Serial.println("apagar peatonales rojo OE EO");
  
}
