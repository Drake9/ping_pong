//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TShape *background;
        TImage *palletBlue;
        TImage *palletRed;
        TImage *ball;
        TTimer *timerBall;
        TTimer *timerBlueLeft;
        TTimer *timerBlueRight;
        TTimer *timerRedLeft;
        TTimer *timerRedRight;
        void __fastcall timerBallTimer(TObject *Sender);
        void __fastcall timerBlueLeftTimer(TObject *Sender);
        void __fastcall timerBlueRightTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall timerRedLeftTimer(TObject *Sender);
        void __fastcall timerRedRightTimer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
