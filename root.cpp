// write a root script to display a plot of the LCC size as a function of p
// data are in a file, e.g., data.txt


#include <iostream>
#include <fstream>
#include <vector>


void plot(){
    gStyle->SetOptStat(0); // Niente box statistiche

    TGraph *gr = new TGraph("./data/ER.txt");
    gr->SetTitle("Largest Cluster Size evolution; N. edges; LCC size");
    gr->SetMarkerStyle(20);
    gr->SetMarkerColor(kBlue+1);
    gr->SetLineColor(kBlue+1);
    gr->SetLineWidth(2);
    gr->SetMarkerSize(0.7);
    gr->Draw("ALP");  // A=axis, L=line, P=points

    TGraph *gr2 = new TGraph("./data/PR.txt");
    gr2->SetMarkerStyle(21);
    gr2->SetMarkerColor(kRed+1);
    gr2->SetLineColor(kRed+1);
    gr2->SetLineWidth(2);
    gr2->SetMarkerSize(0.7);
    gr2->Draw("LP SAME");

    TGraph *gr3 = new TGraph("./data/SR.txt");
    gr3->SetMarkerStyle(22);
    gr3->SetMarkerColor(kGreen+2);
    gr3->SetLineColor(kGreen+2);
    gr3->SetLineWidth(2);
    gr3->SetMarkerSize(0.7);
    gr3->Draw("LP SAME");

    TGraph *gr4 = new TGraph("./data/BF.txt");
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

void plotClusterSize(){
    gStyle->SetOptStat(0); // Niente box statistiche

    TGraph *gr = new TGraph("./data/ERsecond.txt");
    gr->SetTitle("Largest Cluster Size evolution; N. edges; LCC size");
    gr->SetMarkerStyle(20);
    gr->SetMarkerColor(kBlue+1);
    gr->SetLineColor(kBlue+1);
    gr->SetLineWidth(2);
    gr->SetMarkerSize(0.7);
    gr->Draw("ALP");  // A=axis, L=line, P=points

    TGraph *gr2 = new TGraph("./data/PRsecond.txt");
    gr2->SetMarkerStyle(21);
    gr2->SetMarkerColor(kRed+1);
    gr2->SetLineColor(kRed+1);
    gr2->SetLineWidth(2);
    gr2->SetMarkerSize(0.7);
    gr2->Draw("LP SAME");

    TGraph *gr3 = new TGraph("./data/SRsecond.txt");
    gr3->SetMarkerStyle(22);
    gr3->SetMarkerColor(kGreen+2);
    gr3->SetLineColor(kGreen+2);
    gr3->SetLineWidth(2);
    gr3->SetMarkerSize(0.7);
    gr3->Draw("LP SAME");

    TGraph *gr4 = new TGraph("./data/BFsecond.txt");
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

TGraph* MakeGraphFromFile(const char* filename) {
    ifstream in(filename);
    if (!in.is_open()) {
        cout << "Errore: file non trovato: " << filename << endl;
        return nullptr;
    }

    std::vector<double> x, y;
    double v;
    int bin = 0;

    while (in >> v) {
        x.push_back(bin + 0.5);  // centro del bin
        y.push_back(v);
        bin++;
    }

    in.close();
    return new TGraph(x.size(), &x[0], &y[0]);
}

void histo() {
    const int N = 5;
    const char* file_names[N] = {
        "./data/ClusterDistribution/ER_1000.txt",
        "./data/ClusterDistribution/ER_2000.txt",
        "./data/ClusterDistribution/ER_3333.txt",
        "./data/ClusterDistribution/ER_10000.txt",
        "./data/ClusterDistribution/ER_20000.txt"
    };

    const char* labels[N] = {
        "ER1000", "ER2000", "ER3333", "ER10000", "ER20000"
    };

    int colori[N] = {kRed, kBlue, kGreen+2, kMagenta, kOrange+7};

    TGraph* grafici[N];

    TCanvas* c = new TCanvas("c", "Grafici Sovrapposti", 800, 600);
    c->SetGrid();

    for (int i = 0; i < N; ++i) {
        grafici[i] = MakeGraphFromFile(file_names[i]);
        if (!grafici[i]) continue;

        grafici[i]->SetLineColor(colori[i]);
        grafici[i]->SetLineWidth(2);
        grafici[i]->SetMarkerStyle(20 + i);
        grafici[i]->SetMarkerColor(colori[i]);

        if (i == 0)
            grafici[i]->Draw("ALP");  // Axes + Line + Points
        else
            grafici[i]->Draw("LP SAME");
    }

    TLegend* leg = new TLegend(0.7, 0.7, 0.9, 0.9);
    for (int i = 0; i < N; ++i)
        leg->AddEntry(grafici[i], labels[i], "lp");
    leg->Draw();
}


