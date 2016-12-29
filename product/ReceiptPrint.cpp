/*************************************************************************
    > File Name: ReceiptPrint.cpp
    > Author: bjzhang03
    > Mail: bjzhang03@outlook.com
    > Created Time: Fri 28 Oct 2016 09:59:05 PM EDT
 ************************************************************************/

#include<iostream>
#include<vector>
#include<gtk/gtk.h>
#include<string>
#include<map>
#include<set>
#include<sstream>
#include"Bought.h"
#include"Pay.h"
#include"Promotion.h"
#include"Recommend.h"
using namespace std;

//buy goods
string buyGoodData(string code,string name,double price,int count,double promotion)
{
	stringstream IO;
	double sum =0;
	sum=price*count;
	string priceStr;
	IO.clear();
	IO<<price;
	IO>>priceStr;
	IO>>priceStr;
	string countStr;
	IO.clear();
	IO<<count;
	IO>>countStr;
	string PromotionStr;
	IO.clear();
	IO<<promotion;
	IO>>PromotionStr;
	string sumStr;
	IO.clear();
	IO<<sum;
	IO>>sumStr;
	string FinalStr=code+"  "+name+"  "+priceStr+"  "+countStr+"  "+sumStr+"  "+PromotionStr+"\n";
	return FinalStr;
}



//get time
string currenttime()
{
	time_t now;
	struct tm *tm_now;
	char * datetime;
	time(&now);
	tm_now=localtime(&now);
	datetime=asctime(tm_now);
	string result=datetime;
	return result;
}


string PromotionAndRecommend(vector<goodBought> GoodsB)
{
	string PromotionStr="";
	string Recommend="";

	set<string> bought;
	for(int i=0;i<GoodsB.size();i++)
	{
		bought.insert(GoodsB[i].name);
	}
	PromotionData Promote;
	Promote.Promotion();

	pair<pair<string,string>,double> Prom={{"NULL","NULL"},1};
	for(auto it=Promote.ProMap.begin();it!=Promote.ProMap.end();it++)
	{
		/*
		cout<<"Promotion = "<<Prom.first.first<<" - "<<Prom.first.second<<" - "<<Prom.second<<endl;
		*/
		if(bought.find(it->first.first)==bought.end()&&bought.find(it->first.second)!=bought.end())
		{
			if(Prom.second>=it->second)
			{
				Prom.first=it->first;
				Prom.second=it->second;
			}
		}
		if(bought.find(it->first.first)!=bought.end()&&bought.find(it->first.second)==bought.end())
		{
			if(Prom.second>=it->second)
			{
				Prom.first=it->first;
				Prom.second=it->second;
			}
		}
	}

	stringstream IO;
	IO.clear();
	string doubleStr;
	IO<<Prom.second;
	IO>>doubleStr;
	if(1!=Prom.second)
	{
		PromotionStr=Prom.first.first+" and "+Prom.first.second+",discount on "+doubleStr+"\n";
	}


	vector<string> TempReData;
	for(int i=0;i<GoodsB.size();i++)
	{
		TempReData.push_back(GoodsB[i].name);
	}

	//calculate recommend
	RecommendGood ReData;
	ReData.gethistory();
	vector<string> recommendR=ReData.RecommendGoodToPerson(TempReData);

	for(int i=0;i<recommendR.size();i++)
	{
		Recommend=Recommend+recommendR[i]+"  ";
	}

	string result="\nPromotion Caution:\n"+PromotionStr+"\n"+"Recommendation Goods:\n"+Recommend;

	return result;
}


//Deal List
GtkWidget* DealList(vector<goodBought> GoodsB,double payment,string casher,string pos)
{
	string nameTemp="\n                                Wal-Mart Store\n";
	string MarketInformation=nameTemp+"\n"+"--------------------------------Welcome!--------------------------------"+"\n\n"+"********************DEAL*********************\nCode  Name  Price  Count  Expense  Discount\n\n";

	string buyGoods="";
	int totalcount=0;
	double totalprice=0;
	double discountprice=0;
	for(int i=0;i<GoodsB.size();i++)
	{
		totalcount=totalcount+GoodsB[i].count;
		totalprice=totalprice+GoodsB[i].price*GoodsB[i].count;
		discountprice=discountprice+GoodsB[i].price*GoodsB[i].count*GoodsB[i].promotion;
		buyGoods=buyGoods+buyGoodData(GoodsB[i].code,GoodsB[i].name,GoodsB[i].price,GoodsB[i].count,GoodsB[i].promotion);
	}


	string line="---------------------------------------------------------------------------------\n";
	
	stringstream IO;
	
	string totalcountStr;
	string totalpriceStr;
	string discountpriceStr;
	string totalpayStr;
	string totalchangeStr;

	IO.clear();
	IO<<totalcount;
	IO>>totalcountStr;
	IO.clear();
	IO<<totalprice;
	IO>>totalpriceStr;
	IO.clear();
	IO<<discountprice;
	IO>>discountpriceStr;
	IO.clear();
	IO<<payment;
	IO>>totalpayStr;
	IO.clear();
	double change=payment-discountprice;
	IO<<change;
	IO>>totalchangeStr;

	string casherData="total counts: "+totalcountStr+"\n"+"total prices: "+totalpriceStr+"\n"+"discount price: "+discountpriceStr+"\n"+"payment: "+totalpayStr+"      change: "+totalchangeStr+"\n"+"casher: "+casher+"   POS:"+pos+"\n"+"DATE:"+currenttime()+"\n"+"THANK YOU!\n\n";


	string dealinformation=MarketInformation+buyGoods+"\n"+line+casherData+line+PromotionAndRecommend(GoodsB);

	GtkWidget* label =gtk_label_new(dealinformation.c_str());
	return label;
}

//close the app
void closeapp(GtkWidget * window,gpointer data)
{
	gtk_main_quit();
}

//get recommend and promotion
void RPandQR(GtkWidget *hbox)
{

	GtkWidget* label=gtk_label_new("Scan the QR-CODE on the\nright get more promotion\nand recommend\ninformation!");
	GdkPixbuf* src=gdk_pixbuf_new_from_file("./QRCode.jpg",NULL);
	GdkPixbuf* dst=gdk_pixbuf_scale_simple(src,100,100,GDK_INTERP_BILINEAR);

	GtkWidget* image=gtk_image_new_from_pixbuf(dst);

	gtk_box_pack_start(GTK_BOX(hbox),label,TRUE,FALSE,5);
	gtk_box_pack_start(GTK_BOX(hbox),image,TRUE,FALSE,5);
}

int main(int argc,char * argv[])
{
	//init the window
	gtk_init(&argc,&argv);
	GtkWidget *window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window),"Wal-Mart Receipt");
	gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(window),350,500);
	g_signal_connect(GTK_OBJECT(window),"destroy",GTK_SIGNAL_FUNC(closeapp),NULL);

	//define vbox,and hbox
	GtkWidget *vbox,*hbox;
	vbox=gtk_vbox_new(FALSE,5);
	hbox=gtk_hbox_new(FALSE,1);


	BoughtData BUY;
	BUY.BoughtDataInput();

	PayAndCasher PCP;
	PCP.payData();

	//Super market Information
	GtkWidget* label_Information=DealList(BUY.GoodsB,PCP.pay,PCP.casher,PCP.pos);
	RPandQR(hbox);
	gtk_box_pack_start(GTK_BOX(vbox),label_Information,TRUE,TRUE,5);
	gtk_box_pack_start(GTK_BOX(vbox),hbox,FALSE,FALSE,10);


	gtk_container_add(GTK_CONTAINER(window),vbox);
	gtk_widget_show_all(window);
	gtk_main();

	return 0;
}
