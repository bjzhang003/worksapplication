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
#include<sstream>
using namespace std;

//buy goods
string buyGoodData(string code,string name,double price,int count,string promotion)
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
	string sumStr;
	IO.clear();
	IO<<sum;
	IO>>sumStr;
	string FinalStr=code+"  "+name+"  "+priceStr+"  "+countStr+"  "+promotion+"  "+sumStr+"\n";
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


string PromotionAndRecommend()
{
	string Promotion="";
	string Recommend="";

	string result="\n\nPromotion:\n"+Promotion+"\n\n\n"+"Recommendation:\n"+Recommend;

	return result;
}


//Market information
GtkWidget* DealList(vector<string> code,vector<string> name,vector<double> price,vector<int> count,vector<string> promotion,double payment,string casher,string pos)
{
	string nameTemp="                                Wal-Market Store";
	string MarketInformation=nameTemp+"\n"+"--------------------------------Welcome!--------------------------------"+"\n"+"********************DEAL*********************\nCode  Name  Price  Count  Promotion  Sum\n";

	string buyGoods="";
	int totalcount=0;
	double totalprice=0;
	for(int i=0;i<code.size();i++)
	{
		totalcount=totalcount+count[i];
		totalprice=totalprice+price[i]*count[i];
		buyGoods=buyGoods+buyGoodData(code[i],name[i],price[i],count[i],promotion[i]);
	}


	string line="---------------------------------------------------------------------------------\n";
	
	stringstream IO;
	
	string totalcountStr;
	string totalpriceStr;
	string totalpayStr;
	string totalchangeStr;

	IO.clear();
	IO<<totalcount;
	IO>>totalcountStr;
	IO.clear();
	IO<<totalprice;
	IO>>totalpriceStr;
	IO.clear();
	IO<<payment;
	IO>>totalpayStr;
	IO.clear();
	double change=payment-totalprice;
	IO<<change;
	IO>>totalchangeStr;

	string casherData="total counts: "+totalcountStr+"\n"+"total prices: "+totalpriceStr+"\n"+"payment: "+totalpayStr+"      change: "+totalchangeStr+"\n"+"casher: "+casher+"   POS:"+pos+"\n"+"DATE:"+currenttime()+"\n"+"THANK YOU!\n";


	string dealinformation=MarketInformation+buyGoods+line+casherData+line+PromotionAndRecommend();

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

	GtkWidget* label=gtk_label_new("Scan the QR-CODE on the\nright get more promotion\n and recommend\ninformation!");
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
	gtk_window_set_title(GTK_WINDOW(window),"Wal-Market Receipt");
	gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(window),350,200);
	g_signal_connect(GTK_OBJECT(window),"destroy",GTK_SIGNAL_FUNC(closeapp),NULL);

	//define vbox,and hbox
	GtkWidget *vbox,*hbox;
	vbox=gtk_vbox_new(TRUE,10);
	hbox=gtk_hbox_new(FALSE,5);

	vector<string> code;
	vector<string> name;
	vector<double> price;
	vector<int> count;
	vector<string> promotion;
	code.push_back("02080004");
	name.push_back("poker");
	price.push_back(2.50);
	count.push_back(2);
	promotion.push_back("no promotion");
	string casher="zhang";
	string pos="001";

	//Super market Information
	GtkWidget* label_Information=DealList(code,name,price,count,promotion,50,casher,pos);
	RPandQR(hbox);
	gtk_box_pack_start(GTK_BOX(vbox),label_Information,TRUE,TRUE,5);
	gtk_box_pack_start(GTK_BOX(vbox),hbox,FALSE,FALSE,5);


	gtk_container_add(GTK_CONTAINER(window),vbox);
	gtk_widget_show_all(window);
	gtk_main();

	return 0;
}
