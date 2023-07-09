#include<iostream>
#include<string>
using namespace std;


class invoice
{
   private:
      string num;
      string desc;
      int quant;
      double preco;
   public:
   invoice(string n, string d, int q, double p) 
   {
      num = n;
      desc = d;
      quant = q;
      preco = p;
   }

   void setNum(string numero) 
   {
      num = numero;
   }
      string getNum()
   {
      return num;
   }

   void setDesc(string descricao) 
   {
      desc = descricao;
   }
      string getDesc()
   {
      return desc;
   }

   void setQuant(int quantidade) 
   {
   if(quantidade <= 0)
      {
         quant = 0;
      }
   else
      {
         quant = quantidade;
      }
   }
   int getQuant()
   {
      return quant;
   }

   void setPreco(double pr) 
   {
   if(pr <= 0)
      {
         preco = 0.0;
      }
   else
      {
         preco = pr;
      }
   }
   double getPreco()
   {
      return preco;
   }

   double GetInvoiceAmmount()
   {
      return quant * preco;
   } 

};
int main()
{
   string numero;
   string descricao;
   int quantidade;
   double pr, ans;
   invoice In(numero,descricao,quantidade,pr);
   cout<<"Digite o Numero do item faturado"<<endl;
   getline(cin,numero);
   cout<<"Escreva descricao do item"<<endl;
   getline(cin,descricao);
   cout<<"Digite quantidade comprada do item"<<endl;
   cin>>quantidade;
   cout<<"Preco do item"<<endl;
   cin>>pr;
   In.setNum(numero);
   In.getNum();
   In.setDesc(descricao);
   In.getDesc();
   In.setQuant(quantidade);
   In.getQuant();
   In.setPreco(pr);
   In.getPreco();
   ans = In.GetInvoiceAmmount();
   cout<<"invoice ammount e: "<<ans;

 return 0;
}
