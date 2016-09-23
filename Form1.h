#pragma once
// AlgoTrader 2016
// Aleksandr Rabkin, Aysha Aleksandrovich, Alina Peralta, Leonid Korchin
// CIS 4620 - Financial Information Technologies
#include <ctime>

namespace ProjectTemplate {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Windows::Forms::DataVisualization::Charting;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public MetroFramework::Forms::MetroForm
	{
	public:
		DateTime serverTime;
		double dblEMA12;
		double dblSMA12;
		double dblTotal12;
		double dblEMA26;
		double dblSMA26;
		double dblTotal26;
		double MACD9;
		double dblMACD;
		double high;
		double low;
		double fs3;
		double dblCurrentPrice;
		long nextOrderID;
		bool firstRequest = true;
		bool request1Day = false;
		bool MACD_Signal = false;
		bool FS_Signal = false;
		bool VWAP_Signal = false;
		bool CMF_Signal = false;

	public:
		System::Collections::Generic::List<double>^ FS;

		Form1(void)
		{
			InitializeComponent();
			this->Text = "AlgoTrader 2016";
			//
			//TODO: Add the constructor code here
			//
			lstPriceHistory12 = gcnew System::Collections::Generic::List<double>();
			lstPriceHistory26 = gcnew System::Collections::Generic::List<double>();
			lstEMA12 = gcnew System::Collections::Generic::List<double>();
			lstEMA26 = gcnew System::Collections::Generic::List<double>();
			lstSMA12 = gcnew System::Collections::Generic::List<double>();
			lstSMA26 = gcnew System::Collections::Generic::List<double>();
			MACD = gcnew System::Collections::Generic::List<double>();
			OscillatorHigh = gcnew System::Collections::Generic::List<double>();
			OscillatorLow = gcnew System::Collections::Generic::List<double>();
			FS = gcnew System::Collections::Generic::List<double>();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^  lbStatus;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  historicalChart;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chtStock;
	private: System::Windows::Forms::Button^  btnDisconnect;
	private: System::Windows::Forms::ComboBox^  cbTicker;
	private: System::Windows::Forms::GroupBox^  gbHistoricalData;
	private: System::Windows::Forms::GroupBox^  gbIndicators;
	private: System::Windows::Forms::Button^  btnGo;
	private: System::Windows::Forms::Button^  btnConnect;
	private: System::Windows::Forms::Button^  btnRealTimeStop;
	private: System::Windows::Forms::Button^  btnRealTimeStart;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  tbOrderID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  tbOrderStatus;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  tbFilled;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  tbRemaining;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  tbAvgPrice;
	private: AxTWSLib::AxTws^  axTws1;
	private: System::Windows::Forms::Label^  lbSymbol;
	private: System::Windows::Forms::Label^  lblPrice;
	private: System::Windows::Forms::Label^  label2;

		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea3 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea4 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series6 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->lbStatus = (gcnew System::Windows::Forms::ListBox());
			this->historicalChart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chtStock = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->btnDisconnect = (gcnew System::Windows::Forms::Button());
			this->cbTicker = (gcnew System::Windows::Forms::ComboBox());
			this->gbHistoricalData = (gcnew System::Windows::Forms::GroupBox());
			this->gbIndicators = (gcnew System::Windows::Forms::GroupBox());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->tbCMF20 = (gcnew System::Windows::Forms::Label());
			this->lbCMF20status = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->tbVWAP = (gcnew System::Windows::Forms::Label());
			this->lbVWAPstatus = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->tbFS = (gcnew System::Windows::Forms::Label());
			this->tbFS3 = (gcnew System::Windows::Forms::Label());
			this->lbK14status = (gcnew System::Windows::Forms::Label());
			this->lbD143status = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->tbEMA12 = (gcnew System::Windows::Forms::Label());
			this->tbEMA26 = (gcnew System::Windows::Forms::Label());
			this->tbMACD = (gcnew System::Windows::Forms::Label());
			this->tbSignal = (gcnew System::Windows::Forms::Label());
			this->lbEMA12status = (gcnew System::Windows::Forms::Label());
			this->lbEMA26status = (gcnew System::Windows::Forms::Label());
			this->lbMACDstatus = (gcnew System::Windows::Forms::Label());
			this->lbSignal9status = (gcnew System::Windows::Forms::Label());
			this->btnGo = (gcnew System::Windows::Forms::Button());
			this->btnConnect = (gcnew System::Windows::Forms::Button());
			this->btnRealTimeStop = (gcnew System::Windows::Forms::Button());
			this->btnRealTimeStart = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->tbOrderID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tbOrderStatus = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tbFilled = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tbRemaining = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tbAvgPrice = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->axTws1 = (gcnew AxTWSLib::AxTws());
			this->lbSymbol = (gcnew System::Windows::Forms::Label());
			this->lblPrice = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());

			// axTws1
			// 
			this->axTws1->Enabled = true;
			this->axTws1->Location = System::Drawing::Point(900, 740);
			this->axTws1->Name = L"axTws1";
			this->axTws1->OcxState = (cli::safe_cast<System::Windows::Forms::AxHost::State^>(resources->GetObject(L"axTws1.OcxState")));
			this->axTws1->Size = System::Drawing::Size(196, 63);
			this->axTws1->TabIndex = 27;
			this->axTws1->nextValidId += gcnew AxTWSLib::_DTwsEvents_nextValidIdEventHandler(this, &Form1::axTws1_nextValidId);
			this->axTws1->errMsg += gcnew AxTWSLib::_DTwsEvents_errMsgEventHandler(this, &Form1::axTws1_errMsg);
			this->axTws1->orderStatus += gcnew AxTWSLib::_DTwsEvents_orderStatusEventHandler(this, &Form1::axTws1_orderStatus);
			this->axTws1->historicalData += gcnew AxTWSLib::_DTwsEvents_historicalDataEventHandler(this, &Form1::axTws1_historicalData);
			this->axTws1->realtimeBar += gcnew AxTWSLib::_DTwsEvents_realtimeBarEventHandler(this, &Form1::axTws1_realtimeBar);
		}
#pragma endregion

private: System::Void btnConnect_Click(System::Object^  sender, System::EventArgs^  e) {
			 // Connect to the IB Data Server
			 // The First parameter is the IP address of the server. Leave this blank
			 // The Second parameter is the network port. Used the default of 7496
			 // The third parameter is the client application identifier
			 this->axTws1->connect("", 7496, 0);
} //btnConnect_Click end

private: System::Void axTws1_errMsg(System::Object^  sender, AxTWSLib::_DTwsEvents_errMsgEvent^  e) {
			 lbStatus->Items->Add(e->errorCode + " " + e->errorMsg);
} //axTws1_errMsg end

private: System::Void btnRealTimeStart_Click(System::Object^  sender, System::EventArgs^  e) {
			 dblEMA12 = 0;
			 dblTotal12 = 0;
			 dblEMA26 = 0;
			 dblTotal26 = 0;
			 dblMACD = 0;
			 low = 100000;
			 high = 0;
			 fs3 = 0;

			 // Create a new contract object
			 TWSLib::IContract^ ContractInfo = axTws1->createContract();
			 TWSLib::ITagValueList^ mktDataOptions = axTws1->createTagValueList();
			 // Now fill the ContractInfo object with the necessary information 
			 // Contract ID
			 ContractInfo->conId = 0;
			 // Stock symbol
			 ContractInfo->symbol = Convert::ToString(cbTicker->Text);
			 // Type of instrument: Stock=STK,Option=OPT,Future=FUT, etc.
			 ContractInfo->secType = "STK";
			 // The destination of order or request. "SMART" =IB order router
			 ContractInfo->exchange = "SMART";
			 // The primary exchange for the stock.
			 ContractInfo->primaryExchange = "NASDAQ";
			 // The currency of the exchange USD or GBP or CAD or EUR, etc.
			 ContractInfo->currency = "USD";

			 axTws1->reqRealTimeBarsEx(0, ContractInfo, 5, "TRADES", 1, mktDataOptions);
}//btnRealTimeStart_Click end

private: System::Void btnGo_Click(System::Object^  sender, System::EventArgs^  e) {
			 // clear out all elements and re-initialize them (when changing companies)
			 lbSymbol->Text = Convert::ToString(cbTicker->Text);
			 axTws1->cancelRealTimeBars(0);
			 chtStock->Series["Price"]->Points->Clear();
			 chtStock->Series["Volume"]->Points->Clear();
			 historicalChart->Series["Price"]->Points->Clear();
			 historicalChart->Series["Volume"]->Points->Clear();
			 historicalChart->Series["EMA(26)"]->Points->Clear();
			 historicalChart->Series["EMA(12)"]->Points->Clear();
			 
			 lstPriceHistory12->Clear();
			 lstPriceHistory26->Clear();
			 lstEMA12->Clear();
			 lstEMA26->Clear();
			 lstSMA12->Clear();
			 lstSMA26->Clear();
			 MACD->Clear();
			 OscillatorHigh->Clear();
			 OscillatorLow->Clear();
			 FS->Clear();

			 lstChaikinHistoryClose->Clear();
			 lstChaikinHistoryHigh->Clear();
			 lstChaikinHistoryLow->Clear();
			 lstChaikinHistoryVolume->Clear();
			 lstChaikinMoneyFlow->Clear();
			 lstChaikinHistoryMoneyFlowVolume->Clear();
			 temp1->Clear();
			 temp2->Clear();

			 dblEMA12 = 0;
			 dblSMA12 = 0;
			 dblTotal12 = 0;
			 dblEMA26 = 0;
			 dblSMA26 = 0;
			 dblTotal26 = 0;
			 MACD9 = 0;
			 dblMACD = 0;
			 high = 0;
			 low = 0;
			 fs3 = 0;
			 dblCurrentPrice = 0;

			 firstRequest = true;
			 request1Day = false;
			 MACD_Signal = false;
			 FS_Signal = false;
			 VWAP_Signal = false;
			 CMF_Signal = false;

			 dataGridView1->Rows->Clear();
			 dataGridView1->Refresh();

			 tbEMA12->Text = "";
			 tbEMA26->Text = "";
			 tbCMF20->Text = "";
			 tbMACD->Text = "";
			 tbFS->Text = "";
			 tbFS3->Text = "";
			 tbSignal->Text = "";

			 lbCMF20status->Text = "";
			 lbD143status->Text = "";
			 lblPrice->Text = "";
			 lbSignal9status->Text = "";
			 lbVWAPstatus->Text = "";
}//btnGo_Click end

private: System::Void axTws1_realtimeBar(System::Object^  sender, AxTWSLib::_DTwsEvents_realtimeBarEvent^  e) {
			 // A real time bar has been generated. The data is held in object e.
			 // e->time         The time stamp for the bar (seconds since UNIX Epoc)
			 // e->open         Opening (first) price at the start of the bar
			 // e->high         Highest price during the bar
			 // e->low          Lowest price during the bar
			 // e->close        Closing (last) price at the end of the bar
			 // e->volume       Total volume during the bar
			 // e->count        Number of trades (or quotes) during the bar
			 // e->wAP          Volume weighted average price during the bar
			 //
			 // Create a string to hold the completed bar
			 String^ strBarString = gcnew String("");
			 // Define a DateTime to hold the end time of the bar
			 System::DateTime^ dtDateTime = gcnew DateTime(1970, 1, 1, 0, 0, 0, 0, System::DateTimeKind::Utc);
			 // Convert the e.time to a DateTime format
			 dtDateTime = dtDateTime->AddSeconds(e->time).ToLocalTime();
			 // Build up the bar in a string
			 strBarString += dtDateTime + "," + e->open + "," + e->high + ",";
			 strBarString += e->low + "," + e->close + "," + e->volume;
			 // Add the bar to the list box
			 
			 if (e->close > 0.0) {
				 requestHistorical();
				 // Populate charts and current price with realtime bar data
				 chtStock->Series["Price"]->Points->AddXY(dtDateTime, e->low, e->high, e->open, e->close);
				 chtStock->Series["Volume"]->Points->AddXY(dtDateTime, e->volume);
				 lblPrice->Text = Convert::ToString(e->close);
				 dblCurrentPrice = e->close;

				 // MACD Calculations

				 if (lstPriceHistory26->Count > 25){
					 // remove the most recent price and replace with the latest real-time price
					 lstPriceHistory26->RemoveAt(25);
					 lstPriceHistory26->Add(Convert::ToDouble(e->close));

					 dblTotal26 = 0;
					 dblSMA26 = 0;
					 double dblMultiplier = (2 / (26 + 1));

					 for (int i = 0; i < lstPriceHistory26->Count; i++)
					 {
						 dblTotal26 += lstPriceHistory26[i];
						 dblSMA26 = dblTotal26 / lstPriceHistory26->Count;

					 } // end of for loop
					 dblEMA26 = (e->close * dblMultiplier) + dblSMA26 * (1 - dblMultiplier);
					 this->tbEMA26->Text = dblEMA26.ToString("#0.0000");
				 }

				 if (lstPriceHistory12->Count > 11){
					 // remove the most recent price and replace with the latest real-time price
					 lstPriceHistory12->RemoveAt(11);
					 lstPriceHistory12->Add(Convert::ToDouble(e->close));

					 dblTotal12 = 0;
					 dblSMA12 = 0;
					 double dblMultiplier = (2 / (12 + 1));

					 for (int i = 0; i < lstPriceHistory12->Count; i++)
					 {
						 dblTotal12 += lstPriceHistory12[i];
						 dblSMA12 = dblTotal12 / lstPriceHistory12->Count;

					 } // end of for loop
					 dblEMA12 = (e->close * dblMultiplier) + dblSMA12 * (1 - dblMultiplier);
					 MACD->Add(dblEMA12 - dblEMA26);
					 this->tbMACD->Text = MACD[MACD->Count - 1].ToString("#0.0000");

					 this->tbEMA12->Text = dblEMA12.ToString("#0.0000");
				 }
				 
				 if (MACD->Count > 8)
				 {
					 double dblMultiplier = (2 / (9 + 1));
					 double dblMACD_EMA9 = 0;
					 MACD9 = 0;

					 for (int i = 0; i < 9; i++)
					 {
						 MACD9 += MACD[i];
					 }
					 MACD9 = MACD9 / 9;

					 dblMACD_EMA9 = (e->close * dblMultiplier) + MACD9 * (1 - dblMultiplier);
					 this->tbSignal->Text = dblMACD_EMA9.ToString("#0.0000");

					 // MACD(12,26)>Signal(9) => buy signal
					 if (MACD[MACD->Count - 1] > dblMACD_EMA9){
						 MACD_Signal = true;
						 this->lbSignal9status->Text = "Bullish";
						 this->lbSignal9status->ForeColor = System::Drawing::Color::Green;
					 }else if (MACD[MACD->Count - 1] < dblMACD_EMA9){
						 MACD_Signal = false;
						 this->lbSignal9status->Text = "Bearish";
						 this->lbSignal9status->ForeColor = System::Drawing::Color::Red;
					 }

					 MACD->RemoveAt(8);
				 }
				 
				 // Fast Stochastics Calculation

				 if (OscillatorHigh->Count > 13)
				 {
					 // remove the most recent price and replace with the latest real-time price
					 OscillatorHigh->RemoveAt(13);
					 OscillatorLow->RemoveAt(13);
					 OscillatorHigh->Add(Convert::ToDouble(e->high));
					 OscillatorLow->Add(Convert::ToDouble(e->low));

					 high = OscillatorHigh[0];
					 low = OscillatorLow[0];

					 for (int i = 1; i < 14; i++)
					 {
						 if (OscillatorHigh[i] > high)
						 {
							 high = OscillatorHigh[i];
						 }
						 if (OscillatorLow[i] < low)
						 {
							 low = OscillatorLow[i];
						 }
					 }
				 }

				 if (FS->Count > 2){
					 FS->RemoveAt(2);

					 FS->Add((e->close - low) * 100 / (high - low));

					 int count = FS->Count;
					 this->tbFS->Text = FS[count - 1].ToString("#0.0000");

					 for (int i = 0; i < 3; i++)
					 {
						 fs3 += FS[i];
					 }
					 fs3 = fs3 / 3;

					 this->tbFS3->Text = fs3.ToString("#0.0000");
					 
					 // %K(14) goes above %D(14,3) => buy signal
					 if (FS[count - 1] > fs3){
						 FS_Signal = true;
						 this->lbD143status->Text = "Bullish";
						 this->lbD143status->ForeColor = System::Drawing::Color::Green;
					 }
					 else if (FS[count - 1] < fs3){
						 FS_Signal = false;
						 this->lbD143status->Text = "Bearish";
						 this->lbD143status->ForeColor = System::Drawing::Color::Red;
					 }

					 fs3 = 0;
				 }

				 // Place Order
				 // If all signals are green, Buy 100 shares of the stock, can also include VWAP_Signal
				 if (CMF_Signal && MACD_Signal && FS_Signal){
					 // Create a new ContractInfo object
					 TWSLib::IContract^ ContractInfo = axTws1->createContract();
					 // Create a new Order object
					 TWSLib::IOrder^ OrderInfo = axTws1->createOrder();
					 // Fill the ContractInfo object with the necessary information
					 axTws1->reqIds(1);
					 // Connection identifier
					 ContractInfo->conId = 0;
					 // The ticker symbol for the order
					 ContractInfo->symbol = Convert::ToString(cbTicker->Text);
					 // Type of instrument: Stock=STK,Option=OPT,Future=FUT, etc.
					 ContractInfo->secType = "STK";
					 // The Options or Futures expiration data in the format YYYYMM
					 ContractInfo->expiry = "";
					 // The Options Strike Price 
					 ContractInfo->strike = 0;
					 // The Options "PUT" or "CALL" 
					 ContractInfo->right = "";
					 // The contract multiplier for Futures or Options
					 ContractInfo->multiplier = "";
					 // The destination of order or request. "SMART" =IB order router
					 ContractInfo->exchange = "SMART";
					 // The primary exchange where the instrument trades. 
					 // NYSE, NASDAQ, AMEX, BATS, ARCA, PHLX etc.
					 ContractInfo->primaryExchange = "NASDAQ";
					 // The currency of the exchange USD or GBP or CAD or EUR, etc.
					 ContractInfo->currency = "USD";
					 // Fill in the Order information:
					 // orderId is a *Unique* order identifier
					 OrderInfo->orderId = nextOrderID;
					 // Action will be BUY, SELL or SSHORT
					 OrderInfo->action = "BUY";
					 // totalQuantity is the total number of shares (or contracts)
					 OrderInfo->totalQuantity = 100;
					 // orderType is one of MKT, LMT, STP, etc.
					 OrderInfo->orderType = "LMT";
					 // lmtPrice is the limit price for a limit order
					 OrderInfo->lmtPrice = e->close;
					 // timeInForce is either DAY, GTC, IOC, GTD etc.
					 OrderInfo->timeInForce = "DAY";
					 // There are about 40 other properties for different order types...
					 // Submit the order
					 this->axTws1->placeOrderEx(nextOrderID,
						 ContractInfo, OrderInfo);
				 }// end order execution logic
			 }// end if (e->close > 0.0) 
}// axTws1_realtimeBar end

private: System::Void axTws1_historicalData(System::Object^  sender, AxTWSLib::_DTwsEvents_historicalDataEvent^  e) {
			 if (e->close > 0.0) {
				 if (firstRequest){ // run the following on first historical request only
					 // Populate historical chart with data
					 historicalChart->Series["Price"]->Points->AddXY(e->date, e->close);
					 historicalChart->Series["Volume"]->Points->AddXY(e->date, e->volume);

					 lstPriceHistory12->Add(Convert::ToDouble(e->close));
					 lstPriceHistory26->Add(Convert::ToDouble(e->close));
					 OscillatorHigh->Add(Convert::ToDouble(e->high));
					 OscillatorLow->Add(Convert::ToDouble(e->low));

					 // Start MACD calculations

					 if (lstPriceHistory26->Count < 27){
						 dblTotal26 = 0;
						 dblSMA26 = 0;
						 double dblMultiplier = (2 / (26 + 1));

						 for (int i = 0; i < lstPriceHistory26->Count; i++)
						 {
							 dblTotal26 += lstPriceHistory26[i];
							 dblSMA26 = dblTotal26 / lstPriceHistory26->Count;

						 } // end of for loop
						 dblEMA26 = (e->close * dblMultiplier) + dblSMA26 * (1 - dblMultiplier);
						 // Plot EMA(26) series to historical chart
						 historicalChart->Series["EMA(26)"]->Points->AddXY(e->date, dblEMA26);
					 }

					 if (lstPriceHistory12->Count > 12){
						 lstPriceHistory12->RemoveAt(0); // keep the list updated with the latest 12 days of data (remove oldest record if more than 12)
					 }

					 if (lstPriceHistory12->Count < 13){
						 dblTotal12 = 0;
						 dblSMA12 = 0;
						 double dblMultiplier = (2 / (12 + 1));

						 for (int i = 0; i < lstPriceHistory12->Count; i++)
						 {
							 dblTotal12 += lstPriceHistory12[i];
							 dblSMA12 = dblTotal12 / lstPriceHistory12->Count;

						 } // end of for loop
						 dblEMA12 = (e->close * dblMultiplier) + dblSMA12 * (1 - dblMultiplier);
						 // Plot EMA(12) series to historical chart
						 historicalChart->Series["EMA(12)"]->Points->AddXY(e->date, dblEMA12);
					 }

					 // Start Fast Stochastic Calculations

					 if (OscillatorHigh->Count > 14){
						 OscillatorHigh->RemoveAt(0);
					 }

					 if (OscillatorLow->Count > 14){
						 OscillatorLow->RemoveAt(0);
					 }

					 if (OscillatorHigh->Count < 15)
					 {
						 high = OscillatorHigh[0];
						 low = OscillatorLow[0];

						 for (int i = 1; i < 14; i++)
						 {
							 if (OscillatorHigh[i] > high)
							 {
								 high = OscillatorHigh[i];
							 }
							 if (OscillatorLow[i] < low)
							 {
								 low = OscillatorLow[i];
							 }
						 }

						 FS->Add((e->close - low) * 100 / (high - low));

					 }

					 if (FS->Count > 3){
						 FS->RemoveAt(0);
					 }
				 }// end if firstRequest

			 firstRequest = false;		 
}// axTws1_historicalData end

private: System::Void axTws1_nextValidId(System::Object^  sender, AxTWSLib::_DTwsEvents_nextValidIdEvent^  e) {
			 nextOrderID = e->id;
}// end axTws1_nextValidId
private: System::Void axTws1_orderStatus(System::Object^  sender, AxTWSLib::_DTwsEvents_orderStatusEvent^  e) {
			 // Get the status of an order. 
			 // Responds to every change in order status.
			 // Status in in event object e:
			 // e->id              The OrderID (long)
			 // e->status          The status of the order (string)
			 // e->filled          The number of shares/contracts filled in the so far (long)
			 // e->remaining       The number of shares/contracts remaining in the order (long)
			 // e->avgFillPrice    The average fill price (double)
			 // e->permId          The permenent order Id (long)
			 // e->lastFilledPrice The price of the last partial fill (double)
			 // e->clientId        The Id of the client who placed the order (long)

			 // add order status to the dataGrid
			 dataGridView1->Rows->Add(e->id,e->status,e->filled,e->remaining,e->avgFillPrice);
}// axTws1_orderStatus end
private: System::Void historicalChart_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
