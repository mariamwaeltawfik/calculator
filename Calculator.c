#include "StdTypes.h"
#include "DIO_Int.h"
#include "LCD_Int.h"
#include "KeyPad_Int.h"
#include "Calculator.h"
void Delete_Elements(u8 *str,u8 pos){
	u8 i;
	 for (i = pos - 1; str[i]; i++)
	 {
		 str[i] = str[i+1]; // assign arr[i+1] to arr[i]
	 }
	 
}


u16 Multibly(u8 *str)
{  static u8 i,j,res=0;
	u16 x;
	for(i=0;str[i];i++){
		if(str[i]=='*'){
		str[i-1]=str[i-1]*str[i+1];
		
		for(j=i;str[j];j++){
			str[i]=str[j+2];
		}
		}
		}
		for(i=0;str[i];i++){
			if(str[i]=='/'){
				str[i-1]=str[i-1]/str[i+1];
				
				for(j=i;str[j];j++){
					str[i]=str[j+2];
				}
			}
		}
		for(i=0;str[i];i++){
			if(str[i]=='+'){
				res+=str[i-1]+str[i+1];
				}
			
			else if(str[i]=='-'){
				res-=str[i-1]+str[i+1];
			}
			
		}
return res;
}

u16 Store_Equation(void){
	u8 k=KEYPAD_GetKey();
	u16 x;
	static u8 i=0,j=0,flag=0;
	static u16 num,str[17];
	
	if(k>='0'&&k<='9'&&k!='t'){
		
		if (flag==0){
			LCD_SetCursor(2,1);
			LCD_WriteString("                ");
			LCD_SetCursor(1,1);
			LCD_WriteString("                ");
			LCD_SetCursor(1,1);
			flag=1;
		}
		
		num=num*10+k-'0';
		LCD_WriteChar(k);
		
	}
	else if(k=='='){
		flag=0;
		str[i]=num;
		i++;
		str[i]=0;
		x=Multibly(str);
		LCD_SetCursor(2,1);
		LCD_WriteNumber(x);
		
		
		num=0;
		x=0;
		return str;
	}
	else if (k=='+'){
		str[i]=num;
		i++;
		num=0;
		LCD_WriteChar(k);
		str[i]=k;
		i++;
	}
	else if (k=='-'){
		str[i]=num;
		i++;
		LCD_WriteChar(k);
		str[i]=k;
		i++;
		num=0;
	}
	else if (k=='/'){
		str[i]=num;
		i++;
		LCD_WriteChar(k);
		str[i]=k;
		i++;
		num=0;
	}
	else if (k=='*'){
		str[i]=num;
		i++;
		LCD_WriteChar(k);
		str[i]=k;
		i++;
		num=0;
	}
	else if(k=='c'){
		LCD_Clear();
		LCD_SetCursor(2,1);
		LCD_WriteString("                ");
		LCD_SetCursor(1,1);
		LCD_WriteString("                ");
		LCD_SetCursor(1,1);
		num=0;
		i=0;
		j=0;
		x=0;
		
	}

}
void Calculator_Init(void){
	LCD_SetCursor(1,1);
	LCD_WriteString("START CALCULATOR");
	LCD_SetCursor(2,1);
	LCD_WriteString("By: Mariam Wael");
	_delay_ms(2000);
	LCD_Clear();
}
/*u8 count(u32 num){
	static u8 i;
	for(i=0;num;i++){
		num=num/10;
	}
	return i;
}
void Calculator(void){
	u8 k=KEYPAD_GetKey();
	static	u32 num=0,sum=0,res2=0,num2=0;
	static u8 flag=0,i=1,flag2='t',f=0,un_f=0;
	if(k>='0'&&k<='9'&&k!='t'){
		if(f==0){
		
		flag=1;	
		}
		else if (flag==0){
			LCD_SetCursor(1,1);
			LCD_WriteString("          ");
			LCD_SetCursor(2,1);
			LCD_WriteString("          ");
			f=0;
			flag=1;
		}
		
		LCD_SetCursor(1,i);
		i++;
		num=num*10+k-'0';
		
		LCD_WriteChar(k);
	}
	else if(k=='='){
		res2=0;
		if(flag2==SUM){
			sum=num+num2;
			res2=sum;
		}
		else if(flag2==SUB){
			sum=num2-num;
			res2=sum;
		}
	   else if(flag2==MULTI){
			sum=num*num2;
			res2=sum;
		}
		else if(flag2==DIV){
			if(num==0){
				LCD_SetCursor(2,7);
				LCD_WriteString("undefined");
				_delay_ms(1000);
				LCD_Clear();
				LCD_SetCursor(2,1);
				LCD_WriteString("                ");
				LCD_SetCursor(1,1);
				LCD_WriteString("                ");
				LCD_SetCursor(1,1);
				sum=0;
				num=0;
				num2=0;
				i=1;
				f=0;
				un_f=0;
			}
			sum=num2/num;
			
			res2=sum;
		}
		else {
			sum=num;
		}
		if(un_f==0){
			num=0;
			num2=0;
			sum=0;
			flag=0;
			i=1;
			f=1;
			un_f=1;
		}
		else{
			res2=sum;
			LCD_SetCursor(2,1);
			LCD_WriteNumber(sum);
			
			num=0;
			num2=0;
			sum=0;
			flag=0;
			i=1;
			f=1;
		}
		
		
		
	}
	else if (k=='+'){
		
		if(f==1){
			LCD_Clear();
			num2=res2;
			LCD_SetCursor(1,i);
			
			i+=count(num2);
			LCD_WriteNumber(res2);
			LCD_SetCursor(1,i);
			i++;
			LCD_WriteChar(k);
			f=0;
			flag2=SUM;
			
		}
		else{
		num2=num;
		LCD_SetCursor(1,i);
		i++;
		LCD_WriteChar(k);
		num=0;
		flag2=SUM;
		}
		f=0;
	}
	else if (k=='-'){
		
		if(f==1){
			LCD_Clear();
			num2=res2;
			LCD_SetCursor(1,i);
			i+=count(num2);
			LCD_WriteNumber(res2);
			LCD_SetCursor(1,i);
			i++;
			LCD_WriteChar(k);
			f=0;
			flag2=SUB;
			
		}
		else{
		num2=num;
		LCD_SetCursor(1,i);
		i++;
		LCD_WriteChar(k);
		num=0;
		flag2=SUB;
		}
		f=0;
	}
	else if (k=='/'){
		
		if(f==1){
			LCD_Clear();
			num2=res2;
			LCD_SetCursor(1,i);
			i+=count(num2);
			LCD_WriteNumber(res2);
			LCD_SetCursor(1,i);
			i++;
			LCD_WriteChar(k);
			
			flag2=DIV;
			
		}
		else{
			num2=num;
			LCD_SetCursor(1,i);
			i++;
			LCD_WriteChar(k);
			num=0;
			flag2=DIV;
		}
		
		f=0;
	}
	else if (k=='*'){
		
		if(f==1){
			LCD_Clear();
			num2=res2;
			LCD_SetCursor(1,i);
			i+=count(num2);
			LCD_WriteNumber(res2);
			LCD_SetCursor(1,i);
			i++;
			LCD_WriteChar(k);
			f=0;
			flag2=MULTI;
			
		}
		else{
		num2=num;
		LCD_SetCursor(1,i);
		i++;
		LCD_WriteChar(k);
		num=0;
		flag2=MULTI;
		}
		f=0;
	}
	else if(k=='c'){
		LCD_Clear();
		LCD_SetCursor(2,1);
		LCD_WriteString("                ");
		LCD_SetCursor(1,1);
		LCD_WriteString("                ");
		LCD_SetCursor(1,1);
		sum=0;
		num=0;
		num2=0;
		i=1;
		f=0;
	}
}

*/