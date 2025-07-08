// write a root script to display a plot of the LCC size as a function of p
// data are in a file, e.g., data.txt


#include <iostream>
#include <fstream>
#include <vector>

void plotLCC(){
    gStyle->SetOptStat(0);

    TGraph *gr = new TGraph("../data/LCC/ER.txt");
    gr->SetTitle("Largest Cluster Size evolution; N. edges; LCC size");
    gr->SetMarkerStyle(20);
    gr->SetMarkerColor(kBlue+1);
    gr->SetLineColor(kBlue+1);
    gr->SetLineWidth(2);
    gr->SetMarkerSize(0.7);
    gr->Draw("ALP"); 

    TGraph *gr2 = new TGraph("../data/LCC/PR.txt");
    gr2->SetMarkerStyle(21);
    gr2->SetMarkerColor(kRed+1);
    gr2->SetLineColor(kRed+1);
    gr2->SetLineWidth(2);
    gr2->SetMarkerSize(0.7);
    gr2->Draw("LP SAME");

    TGraph *gr3 = new TGraph("../data/LCC/SR.txt");
    gr3->SetMarkerStyle(22);
    gr3->SetMarkerColor(kGreen+2);
    gr3->SetLineColor(kGreen+2);
    gr3->SetLineWidth(2);
    gr3->SetMarkerSize(0.7);
    gr3->Draw("LP SAME");

    TGraph *gr4 = new TGraph("../data/LCC/BF.txt");
    gr4->SetMarkerStyle(23);
    gr4->SetMarkerColor(kOrange+7);
    gr4->SetLineColor(kOrange+7);
    gr4->SetLineWidth(2);
    gr4->SetMarkerSize(0.7);
    gr4->Draw("LP SAME");

    TLegend *legend = new TLegend(0.15, 0.65, 0.4, 0.85);
    legend->AddEntry(gr, "Erdos-Renyi", "lp");
    legend->AddEntry(gr2, "Product Rule", "lp");
    legend->AddEntry(gr3, "Sum Rule", "lp");
    legend->AddEntry(gr4, "BF Rule", "lp");
    legend->SetFillColorAlpha(kWhite, 0.8);
    legend->SetBorderSize(0);
    legend->SetTextSize(0.03);
    legend->Draw();
    // set ylimits

    gPad->SetGridx();
    gPad->SetGridy();

    gPad->Modified();
    gPad->Update();
}


void plotSF(std::string type, double alpha1, double alpha2, double alpha3, double alpha4, int kmin){
    gStyle->SetOptStat(0); // Niente box statistiche

    TGraph *gr = new TGraph(("../data/LCC/"+type+"SF_gamma"+ std::to_string(alpha1)+"_kmin"+std::to_string(kmin)+".txt").c_str());
    gr->SetTitle("Largest Cluster Size evolution; N. edges; LCC size");
    gr->SetMarkerStyle(20);
    gr->SetMarkerColor(kBlue+1);
    gr->SetLineColor(kBlue+1);
    gr->SetLineWidth(2);
    gr->SetMarkerSize(0.7);
    gr->SetMinimum(0);
    gr->SetMaximum(1);
    gr->GetXaxis()->SetLimits(0, 1);
    gr->Draw("ALP");  // A=axis, L=line, P=points

    TGraph *gr2 = new TGraph(("../data/LCC/"+type+"SF_gamma"+ std::to_string(alpha2)+"_kmin"+std::to_string(kmin)+".txt").c_str());
    gr2->SetMarkerStyle(23);
    gr2->SetMarkerColor(kRed+1);
    gr2->SetLineColor(kRed+1);
    gr2->SetLineWidth(2);
    gr2->SetMarkerSize(0.7);
    gr2->SetMinimum(0);
    gr2->SetMaximum(1);
    gr2->GetXaxis()->SetLimits(0, 1);
    gr2->Draw("LP SAME");

    TGraph *gr3 = new TGraph(("../data/LCC/"+type+"SF_gamma"+ std::to_string(alpha3)+"_kmin"+std::to_string(kmin)+".txt").c_str());
    gr3->SetMarkerStyle(23);
    gr3->SetMarkerColor(kOrange+7);
    gr3->SetLineColor(kOrange+7);
    gr3->SetLineWidth(2);
    gr3->SetMarkerSize(0.7);
    gr3->SetMinimum(0);
    gr3->SetMaximum(1);
    gr3->GetXaxis()->SetLimits(0, 1);
    gr3->Draw("LP SAME");

    TGraph *gr4 = new TGraph(("../data/LCC/"+type+"SF_gamma"+ std::to_string(alpha4)+"_kmin"+std::to_string(kmin)+".txt").c_str());
    gr4->SetMarkerStyle(23);
    gr4->SetMarkerColor(kGreen+7);
    gr4->SetLineColor(kGreen+7);
    gr4->SetLineWidth(2);
    gr4->SetMarkerSize(0.7);
    gr4->SetMinimum(0);
    gr4->SetMaximum(1);
    gr4->GetXaxis()->SetLimits(0, 1);
    gr4->Draw("LP SAME");


    //draw a legend
    TLegend *legend = new TLegend(0.15, 0.65, 0.4, 0.85);
    legend->AddEntry(gr, ("gamma = "+ std::to_string(alpha1)).c_str() , "lp");
    legend->AddEntry(gr2, ("gamma = " + std::to_string(alpha2)).c_str(), "lp");
    legend->AddEntry(gr3, ("gamma = " + std::to_string(alpha3)).c_str(), "lp");
    legend->AddEntry(gr4, ("gamma = " + std::to_string(alpha4)).c_str(), "lp");
    legend->SetFillColorAlpha(kWhite, 0.8);
    legend->SetBorderSize(0);
    legend->SetTextSize(0.03);
    legend->Draw();

    gPad->SetGridx();
    gPad->SetGridy();

    gPad->Modified();
    gPad->Update();
}

void plotSLCC(){
    gStyle->SetOptStat(0); // Niente box statistiche

    TGraph *gr = new TGraph("../data/SLCC/ERsecond.txt");
    gr->SetTitle("Largest Cluster Size evolution; N. edges; LCC size");
    gr->SetMarkerStyle(20);
    gr->SetMarkerColor(kBlue+1);
    gr->SetLineColor(kBlue+1);
    gr->SetLineWidth(2);
    gr->SetMarkerSize(0.7);
    gr->Draw("ALP");  // A=axis, L=line, P=points

    TGraph *gr2 = new TGraph("../data/SLCC/PRsecond.txt");
    gr2->SetMarkerStyle(21);
    gr2->SetMarkerColor(kRed+1);
    gr2->SetLineColor(kRed+1);
    gr2->SetLineWidth(2);
    gr2->SetMarkerSize(0.7);
    gr2->Draw("LP SAME");

    TGraph *gr3 = new TGraph("../data/SLCC/SRsecond.txt");
    gr3->SetMarkerStyle(22);
    gr3->SetMarkerColor(kGreen+2);
    gr3->SetLineColor(kGreen+2);
    gr3->SetLineWidth(2);
    gr3->SetMarkerSize(0.7);
    gr3->Draw("LP SAME");

    TGraph *gr4 = new TGraph("../data/SLCC/BFsecond.txt");
    gr4->SetMarkerStyle(23);
    gr4->SetMarkerColor(kOrange+7);
    gr4->SetLineColor(kOrange+7);
    gr4->SetLineWidth(2);
    gr4->SetMarkerSize(0.7);
    gr4->Draw("LP SAME");

    TLegend *legend = new TLegend(0.15, 0.65, 0.4, 0.85);
    legend->AddEntry(gr, "Erdos-Renyi", "lp");
    legend->AddEntry(gr2, "Product Rule", "lp");
    legend->AddEntry(gr3, "Sum Rule", "lp");
    legend->AddEntry(gr4, "BF Rule", "lp");
    legend->SetFillColorAlpha(kWhite, 0.8);
    legend->SetBorderSize(0);
    legend->SetTextSize(0.03);
    legend->Draw();

    gPad->Modified();
    gPad->Update();
}

void plotAvgClusterSize(){
    gStyle->SetOptStat(0); // Niente box statistiche

    TGraph *gr = new TGraph("../data/AvgClusterSize/ERaverage.txt");
    gr->SetTitle("Largest Cluster Size evolution; N. edges; LCC size");
    gr->SetMarkerStyle(20);
    gr->SetMarkerColor(kBlue+1);
    gr->SetLineColor(kBlue+1);
    gr->SetLineWidth(2);
    gr->SetMarkerSize(0.7);
    gr->Draw("ALP");  // A=axis, L=line, P=points

    TGraph *gr2 = new TGraph("../data/AvgClusterSize/PRaverage.txt");
    gr2->SetMarkerStyle(21);
    gr2->SetMarkerColor(kRed+1);
    gr2->SetLineColor(kRed+1);
    gr2->SetLineWidth(2);
    gr2->SetMarkerSize(0.7);
    gr2->Draw("LP SAME");

    TGraph *gr3 = new TGraph("../data/AvgClusterSize/SRaverage.txt");
    gr3->SetMarkerStyle(22);
    gr3->SetMarkerColor(kGreen+2);
    gr3->SetLineColor(kGreen+2);
    gr3->SetLineWidth(2);
    gr3->SetMarkerSize(0.7);
    gr3->Draw("LP SAME");

    TGraph *gr4 = new TGraph("../data/AvgClusterSize/BFaverage.txt");
    gr4->SetMarkerStyle(23);
    gr4->SetMarkerColor(kOrange+7);
    gr4->SetLineColor(kOrange+7);
    gr4->SetLineWidth(2);
    gr4->SetMarkerSize(0.7);
    gr4->Draw("LP SAME");

    TLegend *legend = new TLegend(0.15, 0.65, 0.4, 0.85);
    legend->AddEntry(gr, "Erdos-Renyi", "lp");
    legend->AddEntry(gr2, "Product Rule", "lp");
    legend->AddEntry(gr3, "Sum Rule", "lp");
    legend->AddEntry(gr4, "BF Rule", "lp");
    legend->SetFillColorAlpha(kWhite, 0.8);
    legend->SetBorderSize(0);
    legend->SetTextSize(0.03);
    legend->Draw();

    gPad->Modified();
    gPad->Update();
}



void HistoClusterDistribution(){
    // Canvas 
    TCanvas* c = new TCanvas();
    c->SetLogy();
    c->SetLogx();
    
    // build an histogram reading from a file
    std::ifstream file[5];
    file[0].open("../data/ClusterDistribution/ER_10000.txt");
    file[1].open("../data/ClusterDistribution/ER_30000.txt");
    file[2].open("../data/ClusterDistribution/ER_50000.txt");
    file[3].open("../data/ClusterDistribution/ER_70000.txt");
    file[4].open("../data/ClusterDistribution/ER_90000.txt");

    std::vector<int> data[5];
    for (int i = 0; i < 5; ++i) {
        int value;
        while (file[i] >> value) {
            data[i].push_back(value);
        }
        file[i].close();
    }
    
    // Create a histogram
    TH1F *hist[5];
    for(int i =0; i<5; i++){
        hist[i] = new TH1F("hist", "Hist -> Power Law", 1000000, 1, 1000000); // Notare: bin da 1 in su per log
        for (int val : data[i]) {
            hist[i]->Fill(val);
        }
    }

    std::vector<double> x_vals[5];
    std::vector<double> y_vals[5];
    for(int k = 0; k < 5; k++){
        for (int i = 1; i <= hist[k]->GetNbinsX(); ++i) {
            double x = hist[k]->GetBinCenter(i);
            double y = hist[k]->GetBinContent(i);

            if (x > 0 && y > 0) {  // necessario per scala log
                x_vals[k].push_back(x);
                y_vals[k].push_back(y);
            }
        }

    }
    
    // 3. Crea un TGraph dai vettori
    TGraph* graph = new TGraph(x_vals[0].size(), x_vals[0].data(), y_vals[0].data());
    graph->SetTitle("Log-Log plot dell'istogramma;X;Occorrenze");
    graph->SetMarkerStyle(20);
    graph->SetMarkerSize(0.8);

    // 4. Aggiungi gli altri grafici
    TGraph* graph2 = new TGraph(x_vals[1].size(), x_vals[1].data(), y_vals[1].data());
    graph2->SetMarkerStyle(21);
    graph2->SetMarkerSize(0.8); 

    TGraph* graph3 = new TGraph(x_vals[2].size(), x_vals[2].data(), y_vals[2].data());
    graph3->SetMarkerStyle(22);
    graph3->SetMarkerSize(0.8);

    TGraph* graph4 = new TGraph(x_vals[3].size(), x_vals[3].data(), y_vals[3].data());
    graph4->SetMarkerStyle(23);
    graph4->SetMarkerSize(0.8);

    TGraph* graph5 = new TGraph(x_vals[4].size(), x_vals[4].data(), y_vals[4].data());
    graph5->SetMarkerStyle(24);
    graph5->SetMarkerSize(0.8);

    // 5. Disegna i grafici
    graph->SetLineColor(kBlue+1);
    graph->SetLineWidth(2);
graph->GetXaxis()->SetLimits(1, 1000);
    graph->Draw("ALP"); // A=axes, L=line, P=points
    graph2->SetLineColor(kRed+1);
    graph2->SetLineWidth(2);
    graph2->Draw("LP SAME");
    graph3->SetLineColor(kGreen+2);
    graph3->SetLineWidth(2);
    graph3->Draw("LP SAME");
    graph4->SetLineColor(kOrange+7);
    graph4->SetLineWidth(2);
    graph4->Draw("LP SAME");
    graph5->SetLineColor(kMagenta+2);
    graph5->SetLineWidth(2);
    graph5->Draw("LP SAME");

    // A legend
    TLegend *legend = new TLegend(0.15, 0.65, 0.4, 0.85);
    legend->AddEntry(graph, "p = 49900", "lp");
    legend->AddEntry(graph2, "p = 49950", "lp");
    legend->AddEntry(graph3, "p = 50000", "lp");
    legend->AddEntry(graph4, "p = 50050", "lp");
    legend->AddEntry(graph5, "p = 50100", "lp");
    legend->SetFillColorAlpha(kWhite, 0.8);
    legend->SetBorderSize(0);
    legend->SetTextSize(0.03);
    legend->Draw();

    // limits 

    gPad->SetGridx();
    gPad->SetGridy();
    gPad->Modified();
    gPad->Update();

}

void HistoDD() {
    std::ifstream file("./data/DegreeDistribution/ER.txt");

    TH1F* hist = new TH1F("DegDist", "Degree Distribution", 21, 0, 21); 

    int value;
    while (file >> value) {
        hist->Fill(value);
    }
    file.close();

    TCanvas* c = new TCanvas("c", "Degree Distribution", 900, 700);

    hist->SetTitle("Log-Log plot of Degree Distribution;Degree;Occurrences");
    hist->SetMarkerStyle(20);
    hist->SetMarkerSize(1.0);
    hist->SetLineColor(kBlue + 2);
    hist->SetLineWidth(2);
    hist->SetStats(false);

    hist->GetXaxis()->SetTitleSize(0.045);
    hist->GetXaxis()->SetLabelSize(0.04);
    hist->GetXaxis()->SetTitleOffset(1.2);

    hist->GetYaxis()->SetTitleSize(0.045);
    hist->GetYaxis()->SetLabelSize(0.04);
    hist->GetYaxis()->SetTitleOffset(1.4);

    hist->GetXaxis()->SetRangeUser(1, 100);
c->SetLogx();
c->SetLogy();

    hist->Draw();
// fit a power law to the histogram
    TF1* fit = new TF1("fit", "[0]*pow(x, [1])", 10, 20);
    fit->SetParameters(4.54541e7, -3.2);  // [0] = A, [1] = alpha (esponente)
    hist->Fit(fit, "R"); // Fit the histogram with the power law function       


    c->SetGridx();
    c->SetGridy();

    c->Update();
}


