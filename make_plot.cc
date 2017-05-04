#include <iostream>
#include <cstdlib>
#include <cmath>
#include "TH1F.h"
#include "TFile.h"
#include "TCanvas.h"
#include "THStack.h"
#include "THistPainter.h"
#include "TStyle.h"
#include "TROOT.h"
#include "TPaveStats.h"
#include "TLatex.h"
#include "TLegend.h"
#include <fstream>

using namespace std;

int make_plot(){
    gROOT->SetBatch();
    gStyle->SetOptStat(0);
    gStyle->SetOptTitle(0);

    ifstream input("CF.csv",ios::in);

    TFile output("output.root","RECREATE");

    unsigned int nBins = 333;
    float low = 1.;
    float high = 1e3;

    if(input.is_open()){
        THStack* Endcap = new THStack("Endcap","");
        THStack* BarrelW = new THStack("BarrelW","");
        THStack* BarrelRB = new THStack("BarrelRB","");
        THStack* RPC = new THStack("RPC","");

        TH1F* Total = new TH1F("CMS-RPC","CMS-RPC",nBins,low,high);

        TH1F* E = new TH1F("Endcap-RPC","Endcap",nBins,low,high);
        E->SetFillColor(kRed);
        TH1F* W = new TH1F("Barrel-RPC","Barrel",nBins,low,high);
        W->SetFillColor(kBlue);

        TH1F* E1 = new TH1F("E1","RE#pm1",nBins,low,high);
        E1->SetFillColor(kRed);
        TH1F* E2 = new TH1F("E2","RE#pm2",nBins,low,high);
        E2->SetFillColor(kBlue);
        TH1F* E3 = new TH1F("E3","RE#pm3",nBins,low,high);
        E3->SetFillColor(kGreen);
        TH1F* E4 = new TH1F("E4","RE#pm4",nBins,low,high);
        E4->SetFillColor(kYellow);

        TH1F* WN2 = new TH1F("WN2","W+2",nBins,low,high);
        WN2->SetFillColor(kRed);
        TH1F* WN1 = new TH1F("WN1","W-1",nBins,low,high);
        WN1->SetFillColor(kBlue);
        TH1F* W0 = new TH1F("W0","W0",nBins,low,high);
        W0->SetFillColor(kGreen);
        TH1F* WP1 = new TH1F("WP1","W+1",nBins,low,high);
        WP1->SetFillColor(kYellow);
        TH1F* WP2 = new TH1F("WP2","W+2",nBins,low,high);
        WP2->SetFillColor(kOrange);

        TH1F* RB1 = new TH1F("RB1","RB1",nBins,low,high);
        RB1->SetFillColor(kRed);
        TH1F* RB2 = new TH1F("RB2","RB2",nBins,low,high);
        RB2->SetFillColor(kBlue);
        TH1F* RB3 = new TH1F("RB3","RB3",nBins,low,high);
        RB3->SetFillColor(kGreen);
        TH1F* RB4 = new TH1F("RB4","RB4",nBins,low,high);
        RB4->SetFillColor(kYellow);

        float yH = 0.897;
        float yW = 0.0355;
        float xL = 0.45;
        float xH = 0.75;

        unsigned int cSize = 600;

        TCanvas* cEndcap = new TCanvas("cEndcap", "cEndcap", cSize, cSize);
        cEndcap->SetTopMargin(0.06);
        cEndcap->SetRightMargin(.05);
        cEndcap->SetBottomMargin(1);
        cEndcap->SetLeftMargin(0.12);

        TLegend* legEndcap = new TLegend(xL, yH-4*yW, xH, yH);
        legEndcap->SetBorderSize(0);
        legEndcap->SetFillStyle(0);
        legEndcap->AddEntry(E1,"RE#pm1", "F");
        legEndcap->AddEntry(E2,"RE#pm2", "F");
        legEndcap->AddEntry(E3,"RE#pm3", "F");
        legEndcap->AddEntry(E4,"RE#pm4", "F");

        TCanvas* cBarrelW = new TCanvas("cBarrelW", "cBarrelW", cSize, cSize);
        cBarrelW->SetTopMargin(0.06);
        cBarrelW->SetRightMargin(.05);
        cBarrelW->SetBottomMargin(1);
        cBarrelW->SetLeftMargin(0.12);

        TLegend* legBarrelW = new TLegend(xL, yH-5*yW, xH, yH);
        legBarrelW->SetBorderSize(0);
        legBarrelW->SetFillStyle(0);
        legBarrelW->AddEntry(WN2,"W-2", "F");
        legBarrelW->AddEntry(WN1,"W-1", "F");
        legBarrelW->AddEntry(W0,"W0", "F");
        legBarrelW->AddEntry(WP1,"W+1", "F");
        legBarrelW->AddEntry(WP2,"W+2", "F");

        TCanvas* cBarrelRB = new TCanvas("cBarrelRB", "cBarrelRB", cSize, cSize);
        cBarrelRB->SetTopMargin(0.06);
        cBarrelRB->SetRightMargin(.05);
        cBarrelRB->SetBottomMargin(1);
        cBarrelRB->SetLeftMargin(0.12);

        TLegend* legBarrelRB = new TLegend(xL, yH-4*yW, xH, yH);
        legBarrelRB->SetBorderSize(0);
        legBarrelRB->SetFillStyle(0);
        legBarrelRB->AddEntry(RB1,"RB1", "F");
        legBarrelRB->AddEntry(RB2,"RB2", "F");
        legBarrelRB->AddEntry(RB3,"RB3", "F");
        legBarrelRB->AddEntry(RB4,"RB4", "F");

        TCanvas* cRPC = new TCanvas("cRPC", "cRPC", cSize, cSize);
        cRPC->SetTopMargin(0.06);
        cRPC->SetRightMargin(.05);
        cRPC->SetBottomMargin(1);
        cRPC->SetLeftMargin(0.12);

        TLegend* legRPC= new TLegend(xL, yH-2*yW, xH, yH);
        legRPC->SetBorderSize(0);
        legRPC->SetFillStyle(0);
        legRPC->AddEntry(E,"Endcap", "F");
        legRPC->AddEntry(W,"Barrel", "F");

        while(input.good()){
            char detector = ' ';
            int DiskWheel = -10;
            int roll = 0;
            float rate = -1.;

            input >> detector >> DiskWheel >> roll >> rate;

            if(rate >= 0.){
                if(detector == 'E'){
                    E->Fill(rate);
                    if(abs(DiskWheel) == 1) E1->Fill(rate);
                    if(abs(DiskWheel) == 2) E2->Fill(rate);
                    if(abs(DiskWheel) == 3) E3->Fill(rate);
                    if(abs(DiskWheel) == 4) E4->Fill(rate);
                } else if(detector == 'W'){
                    W->Fill(rate);
                    if(DiskWheel == -2) WN2->Fill(rate);
                    if(DiskWheel == -1) WN1->Fill(rate);
                    if(DiskWheel == 0) W0->Fill(rate);
                    if(DiskWheel == 1) WP1->Fill(rate);
                    if(DiskWheel == 2) WP2->Fill(rate);
                    if(roll == 1) RB1->Fill(rate);
                    if(roll == 2) RB2->Fill(rate);
                    if(roll == 3) RB3->Fill(rate);
                    if(roll == 4) RB4->Fill(rate);
                }
                Total->Fill(rate);
            }
        }

        //********************************************************** FORMATING

        gStyle->SetStatBorderSize(0);
        gStyle->SetStatFontSize(0.035);
        gStyle->SetStatX(0.94);
        gStyle->SetStatW(0.25);
        gStyle->SetStatH(0.3);
        gStyle->SetLegendTextSize(0.032);

        string xLabel = "Extrapolated average rate (Hz/cm^{2})";
        string yLabel = "Number of chambers";

        string leftLabel = "L=5x10^{34}cm^{-2}.s^{-1}, #sqrt{s}=13TeV";
        string topLabel = "#bf{CMS}#scale[0.75]{ #it{Preliminary}}";

        //********************************************************** ENDCAP PLOT

        Endcap->Add(E4);
        Endcap->Add(E3);
        Endcap->Add(E2);
        Endcap->Add(E1);

        cEndcap->cd(0);
        gPad->SetLogx();
        gPad->SetLogy();

        E->Draw();
        Endcap->Draw("SAME");
        Endcap->Draw("SAME AXIS");
        E->GetXaxis()->SetTitleSize(.04);
        E->GetXaxis()->SetTitle(xLabel.c_str());

        E->GetYaxis()->SetTitleOffset(1.5);
        E->GetYaxis()->SetTitleSize(.04);
        E->GetYaxis()->SetTitle(yLabel.c_str());
        E->GetYaxis()->SetRangeUser(0.5,1e3);
        E->SetMinimum(0.5);
        E->SetMaximum(1e3);

        E->GetPainter()->PaintStat(111111,0);

        cEndcap->Modified();

        TLatex* leftTextE = new TLatex();
        leftTextE->SetNDC();
        leftTextE->SetTextFont(43);
        leftTextE->SetTextSize(20);
        leftTextE->SetTextAlign(11);
        leftTextE->DrawLatex(0.55, 1-cEndcap->GetTopMargin()+0.01, leftLabel.c_str());

        TLatex* topTextE = new TLatex();
        topTextE->SetTextFont(42);
        topTextE->SetNDC();
        topTextE->DrawLatex(cEndcap->GetLeftMargin()+0.02, 1-cEndcap->GetTopMargin()+0.01, topLabel.c_str());

        legEndcap->Draw();

        cEndcap->SaveAs("Endcap-Disks-Rate-HL-LHC.png");
        cEndcap->SaveAs("Endcap-Disks-Rate-HL-LHC.pdf");
        cEndcap->Write();

        E1->Write();
        E2->Write();
        E3->Write();
        E4->Write();

        Endcap->Write();

        //********************************************************** BARREL WHEEL PLOT

        BarrelW->Add(W0);
        BarrelW->Add(WN1);
        BarrelW->Add(WP1);
        BarrelW->Add(WN2);
        BarrelW->Add(WP2);

        cBarrelW->cd(0);
        gPad->SetLogx();
        gPad->SetLogy();

        W->Draw();
        BarrelW->Draw("SAME");
        BarrelW->Draw("SAME AXIS");
        W->GetXaxis()->SetTitleSize(.04);
        W->GetXaxis()->SetTitle(xLabel.c_str());

        W->GetYaxis()->SetTitleOffset(1.5);
        W->GetYaxis()->SetTitleSize(.04);
        W->GetYaxis()->SetTitle(yLabel.c_str());
        W->GetYaxis()->SetRangeUser(0.5,1e3);
        W->SetMinimum(0.5);
        W->SetMaximum(1e3);

        W->GetPainter()->PaintStat(111111,0);

        cBarrelW->Modified();

        TLatex* leftTextW = new TLatex();
        leftTextW->SetNDC();
        leftTextW->SetTextFont(43);
        leftTextW->SetTextSize(20);
        leftTextW->SetTextAlign(11);
        leftTextW->DrawLatex(0.55, 1-cBarrelW->GetTopMargin()+0.01, leftLabel.c_str());

        TLatex* topTextW = new TLatex();
        topTextW->SetTextFont(42);
        topTextW->SetNDC();
        topTextW->DrawLatex(cBarrelW->GetLeftMargin()+0.02, 1-cBarrelW->GetTopMargin()+0.01, topLabel.c_str());

        legBarrelW->Draw();

        cBarrelW->SaveAs("Barrel-Wheel-Rate-HL-LHC.png");
        cBarrelW->SaveAs("Barrel-Wheel-Rate-HL-LHC.pdf");
        cBarrelW->Write();

        WN2->Write();
        WN1->Write();
        W0->Write();
        WP1->Write();
        WP2->Write();

        BarrelW->Write();

        //********************************************************** BARREL ROLL PLOT

        BarrelRB->Add(RB1);
        BarrelRB->Add(RB2);
        BarrelRB->Add(RB3);
        BarrelRB->Add(RB4);

        cBarrelRB->cd(0);
        gPad->SetLogx();
        gPad->SetLogy();

        W->Draw();
        BarrelRB->Draw("SAME");
        BarrelRB->Draw("SAME AXIS");
        W->GetXaxis()->SetTitleSize(.04);
        W->GetXaxis()->SetTitle(xLabel.c_str());

        W->GetYaxis()->SetTitleOffset(1.5);
        W->GetYaxis()->SetTitleSize(.04);
        W->GetYaxis()->SetTitle(yLabel.c_str());
        W->GetYaxis()->SetRangeUser(0.5,1e3);
        W->SetMinimum(0.5);
        W->SetMaximum(1e3);

        W->GetPainter()->PaintStat(111111,0);

        cBarrelRB->Modified();

        TLatex* leftTextRB = new TLatex();
        leftTextRB->SetNDC();
        leftTextRB->SetTextFont(43);
        leftTextRB->SetTextSize(20);
        leftTextRB->SetTextAlign(11);
        leftTextRB->DrawLatex(0.55, 1-cBarrelRB->GetTopMargin()+0.01, leftLabel.c_str());

        TLatex* topTextRB = new TLatex();
        topTextRB->SetTextFont(42);
        topTextRB->SetNDC();
        topTextRB->DrawLatex(cBarrelRB->GetLeftMargin()+0.02, 1-cBarrelRB->GetTopMargin()+0.01, topLabel.c_str());

        legBarrelRB->Draw();

        cBarrelRB->SaveAs("Barrel-Roll-Rate-HL-LHC.png");
        cBarrelRB->SaveAs("Barrel-Roll-Rate-HL-LHC.pdf");
        cBarrelRB->Write();

        RB1->Write();
        RB2->Write();
        RB3->Write();
        RB4->Write();

        BarrelRB->Write();

        //********************************************************** CMS RPC PLOT

        RPC->Add(E);
        RPC->Add(W);

        E->SetStats(0);
        W->SetStats(0);

        cRPC->cd(0);
        gPad->SetLogx();
        gPad->SetLogy();

        Total->Draw();
        RPC->Draw("SAME");
        RPC->Draw("SAME AXIS");
        Total->GetXaxis()->SetTitleSize(.04);
        Total->GetXaxis()->SetTitle(xLabel.c_str());

        Total->GetYaxis()->SetTitleOffset(1.5);
        Total->GetYaxis()->SetTitleSize(.04);
        Total->GetYaxis()->SetTitle(yLabel.c_str());
        Total->GetYaxis()->SetRangeUser(0.5,1e3);
        Total->SetMinimum(0.5);
        Total->SetMaximum(1e3);

        Total->GetPainter()->PaintStat(111111,0);

        cRPC->Modified();

        TLatex* leftText = new TLatex();
        leftText->SetNDC();
        leftText->SetTextFont(43);
        leftText->SetTextSize(20);
        leftText->SetTextAlign(11);
        leftText->DrawLatex(0.55, 1-cRPC->GetTopMargin()+0.01, leftLabel.c_str());

        TLatex* topText = new TLatex();
        topText->SetTextFont(42);
        topText->SetNDC();
        topText->DrawLatex(cRPC->GetLeftMargin()+0.02, 1-cRPC->GetTopMargin()+0.01, topLabel.c_str());

        legRPC->Draw();

        cRPC->SaveAs("CMS-RPC-Rate-HL-LHC.png");
        cRPC->SaveAs("CMS-RPC-Rate-HL-LHC.pdf");
        cRPC->Write();

        E->Write();
        W->Write();
        Total->Write();

        RPC->Write();
    }

    output.Close();
    input.close();
    return 0;
}
