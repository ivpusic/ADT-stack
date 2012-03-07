struct tauto {
  int sb, godina;
  char proizvodac[20], model[20];        
};

struct stog{
	tauto automobil;
    stog *next;
};

tauto TopS(stog *S){
	return S->next->automobil;
};

void PushS(tauto x, stog *S){
	stog *novi;
	novi = new stog;
	novi->next = S->next;
	novi->automobil = x;
	S->next = novi;
	return;
};

void PopS(stog *S){
     stog *novi;
     novi = S->next;
     S-next = novi->next;
     delete novi;
};

stog* InitS(stog *S){
  S = new stog;
  S->next = NULL;
  return S;
};

bool IsEmptyS(stog *S){
	if (S->next == NULL) return true;
	return false;
};
