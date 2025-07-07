// write a root script to display a plot of the LCC size as a function of p
// data are in a file, e.g., data.txt


#include <iostream>
#include <fstream>
#include <vector>


void plotLCC(){
    gStyle->SetOptStat(0); // Niente box statistiche

    TGraph *gr = new TGraph("./data/LCC/ER.txt");
    gr->SetTitle("Largest Cluster Size evolution; N. edges; LCC size");
    gr->SetMarkerStyle(20);
    gr->SetMarkerColor(kBlue+1);
    gr->SetLineColor(kBlue+1);
    gr->SetLineWidth(2);
    gr->SetMarkerSize(0.7);
    gr->Draw("ALP");  // A=axis, L=line, P=points

    TGraph *gr2 = new TGraph("./data/LCC/PR.txt");
    gr2->SetMarkerStyle(21);
    gr2->SetMarkerColor(kRed+1);
    gr2->SetLineColor(kRed+1);
    gr2->SetLineWidth(2);
    gr2->SetMarkerSize(0.7);
    gr2->Draw("LP SAME");

    TGraph *gr3 = new TGraph("./data/LCC/SR.txt");
    gr3->SetMarkerStyle(22);
    gr3->SetMarkerColor(kGreen+2);
    gr3->SetLineColor(kGreen+2);
    gr3->SetLineWidth(2);
    gr3->SetMarkerSize(0.7);
    gr3->Draw("LP SAME");

    TGraph *gr4 = new TGraph("./data/LCC/BF.txt");
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

void plotSLCC(){
    gStyle->SetOptStat(0); // Niente box statistiche

    TGraph *gr = new TGraph("./data/SLCC/ERsecond.txt");
    gr->SetTitle("Largest Cluster Size evolution; N. edges; LCC size");
    gr->SetMarkerStyle(20);
    gr->SetMarkerColor(kBlue+1);
    gr->SetLineColor(kBlue+1);
    gr->SetLineWidth(2);
    gr->SetMarkerSize(0.7);
    gr->Draw("ALP");  // A=axis, L=line, P=points

    TGraph *gr2 = new TGraph("./data/SLCC/PRsecond.txt");
    gr2->SetMarkerStyle(21);
    gr2->SetMarkerColor(kRed+1);
    gr2->SetLineColor(kRed+1);
    gr2->SetLineWidth(2);
    gr2->SetMarkerSize(0.7);
    gr2->Draw("LP SAME");

    TGraph *gr3 = new TGraph("./data/SLCC/SRsecond.txt");
    gr3->SetMarkerStyle(22);
    gr3->SetMarkerColor(kGreen+2);
    gr3->SetLineColor(kGreen+2);
    gr3->SetLineWidth(2);
    gr3->SetMarkerSize(0.7);
    gr3->Draw("LP SAME");

    TGraph *gr4 = new TGraph("./data/SLCC/BFsecond.txt");
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

    TGraph *gr = new TGraph("./data/AvgClusterSize/ERaverage.txt");
    gr->SetTitle("Largest Cluster Size evolution; N. edges; LCC size");
    gr->SetMarkerStyle(20);
    gr->SetMarkerColor(kBlue+1);
    gr->SetLineColor(kBlue+1);
    gr->SetLineWidth(2);
    gr->SetMarkerSize(0.7);
    gr->Draw("ALP");  // A=axis, L=line, P=points

    TGraph *gr2 = new TGraph("./data/AvgClusterSize/PRaverage.txt");
    gr2->SetMarkerStyle(21);
    gr2->SetMarkerColor(kRed+1);
    gr2->SetLineColor(kRed+1);
    gr2->SetLineWidth(2);
    gr2->SetMarkerSize(0.7);
    gr2->Draw("LP SAME");

    TGraph *gr3 = new TGraph("./data/AvgClusterSize/SRaverage.txt");
    gr3->SetMarkerStyle(22);
    gr3->SetMarkerColor(kGreen+2);
    gr3->SetLineColor(kGreen+2);
    gr3->SetLineWidth(2);
    gr3->SetMarkerSize(0.7);
    gr3->Draw("LP SAME");

    TGraph *gr4 = new TGraph("./data/AvgClusterSize/BFaverage.txt");
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



