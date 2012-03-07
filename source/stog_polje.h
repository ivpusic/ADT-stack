struct tauto{
   int sb, godina;
   char proizvodac[20], model[20];
};
       
struct stog {
   tauto automobil[51];
   int cursor;
};

tauto TopS (stog* S){
     return S->automobil[S->cursor+1];
};

void PushS (tauto x, stog* S){
  if(S->cursor>=0) {
   S->automobil[S->cursor] = x;
   S->cursor--;
  }
};

void PopS (stog* S) {
     S->cursor++;
};

stog* InitS (stog* S) {
   S = new stog;
   S -> cursor = 49;
   return S;
};

bool IsEmptyS (stog* S) {
   if (S->cursor == 49) return 1;
   return 0;     
}; 
