//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int ballSpeedX = -7,    ballSpeedY = -7;
int palletSpeed = 10;
int hits = 0;
int pointsBlue = 0,     pointsRed = 0;

void viewPointScored(){
        Form1->currentHits->Caption = "liczba odbiæ: " + IntToStr(hits);
        Form1->score->Caption = IntToStr(pointsBlue) + " : " + IntToStr(pointsRed);

        Form1->timerBall->Enabled = false;
        Form1->currentPoint->Visible = true;
        Form1->currentHits->Visible = true;
        Form1->score->Visible = true;
        Form1->nextRound->Visible = true;
        Form1->newGame->Visible = true;

        Form1->nextRound->Enabled = true;
        Form1->newGame->Enabled = true;
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::timerBallTimer(TObject *Sender)
{
        ball->Left += ballSpeedX;
        ball->Top += ballSpeedY;

        //     WALLS BOUNCES
        if(ball->Left-5 <= background->Left)
                ballSpeedX = -ballSpeedX;

        if(ball->Left + ball->Width +5 >= background->Width)
                ballSpeedX = -ballSpeedX;

        //      PALLETS BOUNCES
        if(ball->Left + ball->Width/2 >= palletBlue->Left
           && ball->Left + ball->Width/2 <= palletBlue->Left + palletBlue->Width
           && ball->Top + ball->Height >= palletBlue->Top
           && ballSpeedY > 0){
                ballSpeedY = -ballSpeedY;
                hits++;
        }

        if(ball->Left + ball->Width/2 >= palletRed->Left
           && ball->Left + ball->Width/2 <= palletRed->Left + palletRed->Width
           && ball->Top <= palletRed->Top +palletRed->Height
           && ballSpeedY < 0){
                ballSpeedY = -ballSpeedY;
                hits++;
        }

        //          POINT
        if(ball->Top <= palletRed->Top){
               currentPoint->Caption  = "Punkt dla gracza niebieskiego!";
               pointsBlue++;
               viewPointScored();
        }
        if(ball->Top + ball->Height >= palletBlue->Top + palletBlue->Height){
               currentPoint->Caption  = "Punkt dla gracza czerwonego!";
               pointsRed++;
               viewPointScored();
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::timerBlueLeftTimer(TObject *Sender)
{
        if(palletBlue->Left > 10)
                palletBlue->Left -= palletSpeed;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::timerBlueRightTimer(TObject *Sender)
{
        if(palletBlue->Left + palletBlue->Width < background->Width - 10)
                palletBlue->Left += palletSpeed;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key == VK_LEFT)
                timerBlueLeft->Enabled = true;

        if(Key == VK_RIGHT)
                timerBlueRight->Enabled = true;

        if(Key == 0x41)
                timerRedLeft->Enabled = true;

        if(Key == 0x44)
                timerRedRight->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key == VK_LEFT)
                timerBlueLeft->Enabled = false;

        if(Key == VK_RIGHT)
                timerBlueRight->Enabled = false;

        if(Key == 0x41)
                timerRedLeft->Enabled = false;

        if(Key == 0x44)
                timerRedRight->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::timerRedLeftTimer(TObject *Sender)
{
        if(palletRed->Left > 10)
                palletRed->Left -= palletSpeed;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::timerRedRightTimer(TObject *Sender)
{
        if(palletRed->Left + palletRed->Width < background->Width - 10)
                palletRed->Left += palletSpeed;
}
//---------------------------------------------------------------------------

