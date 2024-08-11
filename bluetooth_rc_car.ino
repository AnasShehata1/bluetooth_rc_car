// define motor pins
#define LF_motor 3
#define LB_motor 2
#define RF_motor 7
#define RB_motor 8
#define R_enable 10
#define L_enable 11

// define the character that represent command and speed
char c = ' ';
int motorSpeed = 100;

// get speed of motor
int getSpeed(char num){
  /*
  if (num == 'q')
  {
    return 100;
  }else{
    return (num-'0')*10;
  }
  */
  switch (num)
  {
    case '1': return 100;
    break;
    case '2': return 110;
    break;
    case '3': return 120;
    break;
    case '4': return 130;
    break;
    case '5': return 140;
    break;
    case '6': return 160;
    break;
    case '7': return 175;
    break;
    case '8': return 190;
    break;
    case '9': return 225;
    break;
    case 'q': return 250;
    break;
    default: return 0;
  }
}

// get status of car
void getCarStatus(char c){
  switch (c)
    {
      case 'F': 
      digitalWrite(LF_motor,HIGH);
      digitalWrite(LB_motor,LOW);
      digitalWrite(RF_motor,HIGH);
      digitalWrite(RB_motor,LOW);
      analogWrite(L_enable,motorSpeed);
      analogWrite(R_enable,motorSpeed);
      break;
      case 'B': 
      digitalWrite(LF_motor,LOW);
      digitalWrite(LB_motor,HIGH);
      digitalWrite(RF_motor,LOW);
      digitalWrite(RB_motor,HIGH);
      analogWrite(L_enable,motorSpeed);
      analogWrite(R_enable,motorSpeed);
      break;
      case 'L': 
      digitalWrite(LF_motor,LOW);
      digitalWrite(LB_motor,HIGH);
      digitalWrite(RF_motor,HIGH);
      digitalWrite(RB_motor,LOW);
      analogWrite(L_enable,motorSpeed);
      analogWrite(R_enable,motorSpeed);
      break;
      case 'R': 
      digitalWrite(LF_motor,HIGH);
      digitalWrite(LB_motor,LOW);
      digitalWrite(RF_motor,LOW);
      digitalWrite(RB_motor,HIGH);
      analogWrite(L_enable,motorSpeed);
      analogWrite(R_enable,motorSpeed);
      break;
      case 'G': // forward left
      digitalWrite(LF_motor,HIGH);
      digitalWrite(LB_motor,LOW);
      digitalWrite(RF_motor,HIGH);
      digitalWrite(RB_motor,LOW);
      analogWrite(L_enable,0);
      analogWrite(R_enable,motorSpeed);
      break;
      case 'I': // forward right
      digitalWrite(LF_motor,HIGH);
      digitalWrite(LB_motor,LOW);
      digitalWrite(RF_motor,HIGH);
      digitalWrite(RB_motor,LOW);
      analogWrite(L_enable,motorSpeed);
      analogWrite(R_enable,0);
      break;
      case 'H': //  back left
      digitalWrite(LF_motor,LOW);
      digitalWrite(LB_motor,HIGH);
      digitalWrite(RF_motor,LOW);
      digitalWrite(RB_motor,HIGH);
      analogWrite(L_enable,0);
      analogWrite(R_enable,motorSpeed);
      break;
      case 'J': //  back right
      digitalWrite(LF_motor,LOW);
      digitalWrite(LB_motor,HIGH);
      digitalWrite(RF_motor,LOW);
      digitalWrite(RB_motor,HIGH);
      analogWrite(L_enable,motorSpeed);
      analogWrite(R_enable,0);
      break;
      default:   
      digitalWrite(LF_motor,LOW);
      digitalWrite(LB_motor,LOW);
      digitalWrite(RF_motor,LOW);
      digitalWrite(RB_motor,LOW);
    }
}

void setup() {
  Serial.begin(9600);
  pinMode(LF_motor,OUTPUT);
  pinMode(LB_motor,OUTPUT);
  pinMode(RF_motor,OUTPUT);
  pinMode(LB_motor,OUTPUT);
  pinMode(L_enable,OUTPUT);
  pinMode(R_enable,OUTPUT);

}

void loop() {
      
  if(Serial.available()>0)
  {
    {
      c = Serial.read();
    
      // if it's between '1' or '9' or equal 'q'  so it's speed
      if (c > '0' && c <= '9' || c == 'q')
      {
        motorSpeed=getSpeed(c);
      }
      else
      {
        getCarStatus(c);
      }
      
    }
  }
  
}
