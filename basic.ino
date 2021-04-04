//Software basic do sistema educacional FR13
//Módulo básico
//Autor: Geison Mancuzo
//04/04/2021
//Versão 1.210404b

//Definição de pinos
int led1 = 5;
int led2 = 6;
int ch1 = 2;
int ch2 = 4;
int ad = A3;

//Pinos auxiliares
int gnd = 3;
int gnd1 = 15;
int vcc = 19;

//Variáveis
int filtroCh1 = 0;
int filtroCh2 = 0;
int funcaoLed1 = 0;
int astavel = 0;

bool controleCh1 = false;
bool controleCh2 = false;

//Funções
void trataLed1();

void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(ch1, INPUT_PULLUP);
  pinMode(ch2, INPUT_PULLUP);

  pinMode(gnd, OUTPUT);
  digitalWrite(gnd, LOW);

  pinMode(gnd1, OUTPUT);
  digitalWrite(gnd1, LOW);

  pinMode(vcc, OUTPUT);
  digitalWrite(vcc, HIGH);
}

void loop()
{
  if (!digitalRead(ch1))
  {
    if (!controleCh1)
    {
      filtroCh1++;
      if (filtroCh1 > 30)
      {
        filtroCh1 = 0;
        controleCh1 = true;
        funcaoLed1++;
        if (funcaoLed1 > 2)
        {
          funcaoLed1 = 0;
        }
      }
    }
  }
  else
  {
    controleCh1 = false;
  }
  trataLed1();

  if (!digitalRead(ch2))
  {
    if (!controleCh2)
    {
      filtroCh2++;
      if (filtroCh2 > 30)
      {
        filtroCh2 = 0;
        trataLed2();
      }
    }
  }
  else
  {
    controleCh2 = false;
  }
  trataLed2;
  delay(10);
}

void trataLed1()
{
  switch (funcaoLed1)
  {
  case 0:
    digitalWrite(led1, LOW);
    break;
  case 1:
    analogWrite(led1, (analogRead(ad) / 4));
    break;
  case 2:
    astavel++;
    if (astavel > (analogRead(ad) / 6))
    {
      astavel = 0;
      if (digitalRead(led1))
      {
        digitalWrite(led1, LOW);
      }
      else
      {
        digitalWrite(led1, HIGH);
      }
    }
    break;
  default:
    break;
  }
}

void trataLed2()
{
  if (digitalRead(led2))
  {
    digitalWrite(led2, LOW);
  }
  else
  {
    digitalWrite(led2, HIGH);
  }
}