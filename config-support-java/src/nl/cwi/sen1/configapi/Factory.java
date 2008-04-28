package nl.cwi.sen1.configapi;

public class Factory {
  private aterm.pure.PureFactory factory;


  private aterm.AFun fun_VirtualButton_NOBUTTON;
  private aterm.ATerm pattern_VirtualButton_NOBUTTON;
  private aterm.AFun fun_VirtualButton_BUTTON1;
  private aterm.ATerm pattern_VirtualButton_BUTTON1;
  private aterm.AFun fun_VirtualButton_BUTTON2;
  private aterm.ATerm pattern_VirtualButton_BUTTON2;
  private aterm.AFun fun_VirtualButton_BUTTON3;
  private aterm.ATerm pattern_VirtualButton_BUTTON3;

  private aterm.AFun fun_KeyModifier_MUnderscoreALT;
  private aterm.ATerm pattern_KeyModifier_MUnderscoreALT;
  private aterm.AFun fun_KeyModifier_MUnderscoreCTRL;
  private aterm.ATerm pattern_KeyModifier_MUnderscoreCTRL;
  private aterm.AFun fun_KeyModifier_MUnderscoreSHIFT;
  private aterm.ATerm pattern_KeyModifier_MUnderscoreSHIFT;

  private aterm.AFun fun_VirtualKey_VKUnderscore0;
  private aterm.ATerm pattern_VirtualKey_VKUnderscore0;
  private aterm.AFun fun_VirtualKey_VKUnderscore1;
  private aterm.ATerm pattern_VirtualKey_VKUnderscore1;
  private aterm.AFun fun_VirtualKey_VKUnderscore2;
  private aterm.ATerm pattern_VirtualKey_VKUnderscore2;
  private aterm.AFun fun_VirtualKey_VKUnderscore3;
  private aterm.ATerm pattern_VirtualKey_VKUnderscore3;
  private aterm.AFun fun_VirtualKey_VKUnderscore4;
  private aterm.ATerm pattern_VirtualKey_VKUnderscore4;
  private aterm.AFun fun_VirtualKey_VKUnderscore5;
  private aterm.ATerm pattern_VirtualKey_VKUnderscore5;
  private aterm.AFun fun_VirtualKey_VKUnderscore6;
  private aterm.ATerm pattern_VirtualKey_VKUnderscore6;
  private aterm.AFun fun_VirtualKey_VKUnderscore7;
  private aterm.ATerm pattern_VirtualKey_VKUnderscore7;
  private aterm.AFun fun_VirtualKey_VKUnderscore8;
  private aterm.ATerm pattern_VirtualKey_VKUnderscore8;
  private aterm.AFun fun_VirtualKey_VKUnderscore9;
  private aterm.ATerm pattern_VirtualKey_VKUnderscore9;
  private aterm.AFun fun_VirtualKey_VKUnderscoreA;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreA;
  private aterm.AFun fun_VirtualKey_VKUnderscoreB;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreB;
  private aterm.AFun fun_VirtualKey_VKUnderscoreC;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreC;
  private aterm.AFun fun_VirtualKey_VKUnderscoreD;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreD;
  private aterm.AFun fun_VirtualKey_VKUnderscoreE;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreE;
  private aterm.AFun fun_VirtualKey_VKUnderscoreF;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreF;
  private aterm.AFun fun_VirtualKey_VKUnderscoreG;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreG;
  private aterm.AFun fun_VirtualKey_VKUnderscoreH;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreH;
  private aterm.AFun fun_VirtualKey_VKUnderscoreI;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreI;
  private aterm.AFun fun_VirtualKey_VKUnderscoreJ;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreJ;
  private aterm.AFun fun_VirtualKey_VKUnderscoreK;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreK;
  private aterm.AFun fun_VirtualKey_VKUnderscoreL;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreL;
  private aterm.AFun fun_VirtualKey_VKUnderscoreM;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreM;
  private aterm.AFun fun_VirtualKey_VKUnderscoreN;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreN;
  private aterm.AFun fun_VirtualKey_VKUnderscoreO;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreO;
  private aterm.AFun fun_VirtualKey_VKUnderscoreP;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreP;
  private aterm.AFun fun_VirtualKey_VKUnderscoreQ;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreQ;
  private aterm.AFun fun_VirtualKey_VKUnderscoreR;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreR;
  private aterm.AFun fun_VirtualKey_VKUnderscoreS;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreS;
  private aterm.AFun fun_VirtualKey_VKUnderscoreT;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreT;
  private aterm.AFun fun_VirtualKey_VKUnderscoreU;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreU;
  private aterm.AFun fun_VirtualKey_VKUnderscoreV;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreV;
  private aterm.AFun fun_VirtualKey_VKUnderscoreW;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreW;
  private aterm.AFun fun_VirtualKey_VKUnderscoreX;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreX;
  private aterm.AFun fun_VirtualKey_VKUnderscoreY;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreY;
  private aterm.AFun fun_VirtualKey_VKUnderscoreZ;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreZ;
  private aterm.AFun fun_VirtualKey_VKUnderscoreAMPERSAND;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreAMPERSAND;
  private aterm.AFun fun_VirtualKey_VKUnderscoreASTERISK;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreASTERISK;
  private aterm.AFun fun_VirtualKey_VKUnderscoreAT;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreAT;
  private aterm.AFun fun_VirtualKey_VKUnderscoreBACKUnderscoreQUOTE;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreBACKUnderscoreQUOTE;
  private aterm.AFun fun_VirtualKey_VKUnderscoreBACKUnderscoreSLASH;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreBACKUnderscoreSLASH;
  private aterm.AFun fun_VirtualKey_VKUnderscoreBACKUnderscoreSPACE;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreBACKUnderscoreSPACE;
  private aterm.AFun fun_VirtualKey_VKUnderscoreBEGIN;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreBEGIN;
  private aterm.AFun fun_VirtualKey_VKUnderscoreBRACEUnderscoreLEFT;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreBRACEUnderscoreLEFT;
  private aterm.AFun fun_VirtualKey_VKUnderscoreBRACEUnderscoreRIGHT;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreBRACEUnderscoreRIGHT;
  private aterm.AFun fun_VirtualKey_VKUnderscoreCIRCUMFLEX;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreCIRCUMFLEX;
  private aterm.AFun fun_VirtualKey_VKUnderscoreCLEAR;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreCLEAR;
  private aterm.AFun fun_VirtualKey_VKUnderscoreCLOSEUnderscoreBRACKET;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreCLOSEUnderscoreBRACKET;
  private aterm.AFun fun_VirtualKey_VKUnderscoreCOLON;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreCOLON;
  private aterm.AFun fun_VirtualKey_VKUnderscoreCOMMA;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreCOMMA;
  private aterm.AFun fun_VirtualKey_VKUnderscoreDECIMAL;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreDECIMAL;
  private aterm.AFun fun_VirtualKey_VKUnderscoreDELETE;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreDELETE;
  private aterm.AFun fun_VirtualKey_VKUnderscoreDIVIDE;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreDIVIDE;
  private aterm.AFun fun_VirtualKey_VKUnderscoreDOLLAR;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreDOLLAR;
  private aterm.AFun fun_VirtualKey_VKUnderscoreDOWN;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreDOWN;
  private aterm.AFun fun_VirtualKey_VKUnderscoreEND;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreEND;
  private aterm.AFun fun_VirtualKey_VKUnderscoreENTER;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreENTER;
  private aterm.AFun fun_VirtualKey_VKUnderscoreEQUALS;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreEQUALS;
  private aterm.AFun fun_VirtualKey_VKUnderscoreESCAPE;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreESCAPE;
  private aterm.AFun fun_VirtualKey_VKUnderscoreEXCLAMATIONUnderscoreMARK;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreEXCLAMATIONUnderscoreMARK;
  private aterm.AFun fun_VirtualKey_VKUnderscoreF1;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreF1;
  private aterm.AFun fun_VirtualKey_VKUnderscoreF2;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreF2;
  private aterm.AFun fun_VirtualKey_VKUnderscoreF3;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreF3;
  private aterm.AFun fun_VirtualKey_VKUnderscoreF4;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreF4;
  private aterm.AFun fun_VirtualKey_VKUnderscoreF5;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreF5;
  private aterm.AFun fun_VirtualKey_VKUnderscoreF6;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreF6;
  private aterm.AFun fun_VirtualKey_VKUnderscoreF7;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreF7;
  private aterm.AFun fun_VirtualKey_VKUnderscoreF8;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreF8;
  private aterm.AFun fun_VirtualKey_VKUnderscoreF9;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreF9;
  private aterm.AFun fun_VirtualKey_VKUnderscoreF10;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreF10;
  private aterm.AFun fun_VirtualKey_VKUnderscoreF11;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreF11;
  private aterm.AFun fun_VirtualKey_VKUnderscoreF12;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreF12;
  private aterm.AFun fun_VirtualKey_VKUnderscoreGREATER;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreGREATER;
  private aterm.AFun fun_VirtualKey_VKUnderscoreHOME;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreHOME;
  private aterm.AFun fun_VirtualKey_VKUnderscoreINSERT;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreINSERT;
  private aterm.AFun fun_VirtualKey_VKUnderscoreLEFT;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreLEFT;
  private aterm.AFun fun_VirtualKey_VKUnderscoreLEFTUnderscorePARENTHESIS;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreLEFTUnderscorePARENTHESIS;
  private aterm.AFun fun_VirtualKey_VKUnderscoreMINUS;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreMINUS;
  private aterm.AFun fun_VirtualKey_VKUnderscoreMULTIPLY;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreMULTIPLY;
  private aterm.AFun fun_VirtualKey_VKUnderscoreNUMBERUnderscoreSIGN;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreNUMBERUnderscoreSIGN;
  private aterm.AFun fun_VirtualKey_VKUnderscoreOPENUnderscoreBRACKET;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreOPENUnderscoreBRACKET;
  private aterm.AFun fun_VirtualKey_VKUnderscorePAGEUnderscoreDOWN;
  private aterm.ATerm pattern_VirtualKey_VKUnderscorePAGEUnderscoreDOWN;
  private aterm.AFun fun_VirtualKey_VKUnderscorePAGEUnderscoreUP;
  private aterm.ATerm pattern_VirtualKey_VKUnderscorePAGEUnderscoreUP;
  private aterm.AFun fun_VirtualKey_VKUnderscorePAUSE;
  private aterm.ATerm pattern_VirtualKey_VKUnderscorePAUSE;
  private aterm.AFun fun_VirtualKey_VKUnderscorePERIOD;
  private aterm.ATerm pattern_VirtualKey_VKUnderscorePERIOD;
  private aterm.AFun fun_VirtualKey_VKUnderscorePLUS;
  private aterm.ATerm pattern_VirtualKey_VKUnderscorePLUS;
  private aterm.AFun fun_VirtualKey_VKUnderscorePRINTSCREEN;
  private aterm.ATerm pattern_VirtualKey_VKUnderscorePRINTSCREEN;
  private aterm.AFun fun_VirtualKey_VKUnderscoreQUOTE;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreQUOTE;
  private aterm.AFun fun_VirtualKey_VKUnderscoreQUOTEDBL;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreQUOTEDBL;
  private aterm.AFun fun_VirtualKey_VKUnderscoreRIGHT;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreRIGHT;
  private aterm.AFun fun_VirtualKey_VKUnderscoreRIGHTUnderscorePARENTHESIS;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreRIGHTUnderscorePARENTHESIS;
  private aterm.AFun fun_VirtualKey_VKUnderscoreSEMICOLON;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreSEMICOLON;
  private aterm.AFun fun_VirtualKey_VKUnderscoreSLASH;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreSLASH;
  private aterm.AFun fun_VirtualKey_VKUnderscoreSPACE;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreSPACE;
  private aterm.AFun fun_VirtualKey_VKUnderscoreSUBTRACT;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreSUBTRACT;
  private aterm.AFun fun_VirtualKey_VKUnderscoreTAB;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreTAB;
  private aterm.AFun fun_VirtualKey_VKUnderscoreUNDERSCORE;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreUNDERSCORE;
  private aterm.AFun fun_VirtualKey_VKUnderscoreUP;
  private aterm.ATerm pattern_VirtualKey_VKUnderscoreUP;

  private aterm.AFun fun_Color_Rgb;
  private aterm.ATerm pattern_Color_Rgb;

  private aterm.AFun fun_Configuration_Configuration;
  private aterm.ATerm pattern_Configuration_Configuration;

  private aterm.AFun fun_Property_Import;
  private aterm.ATerm pattern_Property_Import;
  private aterm.AFun fun_Property_Script;
  private aterm.ATerm pattern_Property_Script;
  private aterm.AFun fun_Property_ScriptPath;
  private aterm.ATerm pattern_Property_ScriptPath;
  private aterm.AFun fun_Property_Action;
  private aterm.ATerm pattern_Property_Action;
  private aterm.AFun fun_Property_Editor;
  private aterm.ATerm pattern_Property_Editor;
  private aterm.AFun fun_Property_LibraryPath;
  private aterm.ATerm pattern_Property_LibraryPath;
  private aterm.AFun fun_Property_ModulePath;
  private aterm.ATerm pattern_Property_ModulePath;
  private aterm.AFun fun_Property_TextCategory;
  private aterm.ATerm pattern_Property_TextCategory;

  private aterm.AFun fun_ActionDescription_Description;
  private aterm.ATerm pattern_ActionDescription_Description;

  private aterm.AFun fun_Event_Popup;
  private aterm.ATerm pattern_Event_Popup;
  private aterm.AFun fun_Event_Click;
  private aterm.ATerm pattern_Event_Click;
  private aterm.AFun fun_Event_Icon;
  private aterm.ATerm pattern_Event_Icon;
  private aterm.AFun fun_Event_Menu;
  private aterm.ATerm pattern_Event_Menu;
  private aterm.AFun fun_Event_MenuShortcut;
  private aterm.ATerm pattern_Event_MenuShortcut;

  private aterm.AFun fun_Item_Label;
  private aterm.ATerm pattern_Item_Label;

  private aterm.AFun fun_TextCategoryName_Focus;
  private aterm.ATerm pattern_TextCategoryName_Focus;
  private aterm.AFun fun_TextCategoryName_Selection;
  private aterm.ATerm pattern_TextCategoryName_Selection;
  private aterm.AFun fun_TextCategoryName_Normal;
  private aterm.ATerm pattern_TextCategoryName_Normal;
  private aterm.AFun fun_TextCategoryName_Extern;
  private aterm.ATerm pattern_TextCategoryName_Extern;

  private aterm.AFun fun_TextAttribute_ForegroundColor;
  private aterm.ATerm pattern_TextAttribute_ForegroundColor;
  private aterm.AFun fun_TextAttribute_BackgroundColor;
  private aterm.ATerm pattern_TextAttribute_BackgroundColor;
  private aterm.AFun fun_TextAttribute_Style;
  private aterm.ATerm pattern_TextAttribute_Style;
  private aterm.AFun fun_TextAttribute_Font;
  private aterm.ATerm pattern_TextAttribute_Font;
  private aterm.AFun fun_TextAttribute_Size;
  private aterm.ATerm pattern_TextAttribute_Size;

  private aterm.AFun fun_ShortCut_Shortcut;
  private aterm.ATerm pattern_ShortCut_Shortcut;

  private aterm.AFun fun_TextStyle_Bold;
  private aterm.ATerm pattern_TextStyle_Bold;
  private aterm.AFun fun_TextStyle_Italics;
  private aterm.ATerm pattern_TextStyle_Italics;
  private aterm.AFun fun_TextStyle_Underlined;
  private aterm.ATerm pattern_TextStyle_Underlined;






  private nl.cwi.sen1.configapi.types.PropertyList empty_PropertyList;
  private nl.cwi.sen1.configapi.types.ActionDescriptionList empty_ActionDescriptionList;
  private nl.cwi.sen1.configapi.types.TextAttributeMap empty_TextAttributeMap;
  private nl.cwi.sen1.configapi.types.KeyModifierList empty_KeyModifierList;
  private nl.cwi.sen1.configapi.types.ItemLabels empty_ItemLabels;

  private Factory(aterm.pure.PureFactory factory) {
    this.factory = factory;
  }

  private static Factory instance = null;

  public synchronized static Factory getInstance(aterm.pure.PureFactory factory) {
    if (instance == null) {
        instance = new Factory(factory);
        instance.initialize();
    }
    if (instance.factory != factory) {
        throw new RuntimeException("Don't create two Factory factories with differents PureFactory ");
    }
    return instance;
  }

  public aterm.pure.PureFactory getPureFactory() {
    return factory;
  }

  private void initialize() {

    pattern_VirtualButton_NOBUTTON = factory.parse("NOBUTTON");
    fun_VirtualButton_NOBUTTON = factory.makeAFun("_VirtualButton_NOBUTTON", 0, false);

    pattern_VirtualButton_BUTTON1 = factory.parse("BUTTON1");
    fun_VirtualButton_BUTTON1 = factory.makeAFun("_VirtualButton_BUTTON1", 0, false);

    pattern_VirtualButton_BUTTON2 = factory.parse("BUTTON2");
    fun_VirtualButton_BUTTON2 = factory.makeAFun("_VirtualButton_BUTTON2", 0, false);

    pattern_VirtualButton_BUTTON3 = factory.parse("BUTTON3");
    fun_VirtualButton_BUTTON3 = factory.makeAFun("_VirtualButton_BUTTON3", 0, false);

    pattern_KeyModifier_MUnderscoreALT = factory.parse("M_ALT");
    fun_KeyModifier_MUnderscoreALT = factory.makeAFun("_KeyModifier_M_ALT", 0, false);

    pattern_KeyModifier_MUnderscoreCTRL = factory.parse("M_CTRL");
    fun_KeyModifier_MUnderscoreCTRL = factory.makeAFun("_KeyModifier_M_CTRL", 0, false);

    pattern_KeyModifier_MUnderscoreSHIFT = factory.parse("M_SHIFT");
    fun_KeyModifier_MUnderscoreSHIFT = factory.makeAFun("_KeyModifier_M_SHIFT", 0, false);

    pattern_VirtualKey_VKUnderscore0 = factory.parse("VK_0");
    fun_VirtualKey_VKUnderscore0 = factory.makeAFun("_VirtualKey_VK_0", 0, false);

    pattern_VirtualKey_VKUnderscore1 = factory.parse("VK_1");
    fun_VirtualKey_VKUnderscore1 = factory.makeAFun("_VirtualKey_VK_1", 0, false);

    pattern_VirtualKey_VKUnderscore2 = factory.parse("VK_2");
    fun_VirtualKey_VKUnderscore2 = factory.makeAFun("_VirtualKey_VK_2", 0, false);

    pattern_VirtualKey_VKUnderscore3 = factory.parse("VK_3");
    fun_VirtualKey_VKUnderscore3 = factory.makeAFun("_VirtualKey_VK_3", 0, false);

    pattern_VirtualKey_VKUnderscore4 = factory.parse("VK_4");
    fun_VirtualKey_VKUnderscore4 = factory.makeAFun("_VirtualKey_VK_4", 0, false);

    pattern_VirtualKey_VKUnderscore5 = factory.parse("VK_5");
    fun_VirtualKey_VKUnderscore5 = factory.makeAFun("_VirtualKey_VK_5", 0, false);

    pattern_VirtualKey_VKUnderscore6 = factory.parse("VK_6");
    fun_VirtualKey_VKUnderscore6 = factory.makeAFun("_VirtualKey_VK_6", 0, false);

    pattern_VirtualKey_VKUnderscore7 = factory.parse("VK_7");
    fun_VirtualKey_VKUnderscore7 = factory.makeAFun("_VirtualKey_VK_7", 0, false);

    pattern_VirtualKey_VKUnderscore8 = factory.parse("VK_8");
    fun_VirtualKey_VKUnderscore8 = factory.makeAFun("_VirtualKey_VK_8", 0, false);

    pattern_VirtualKey_VKUnderscore9 = factory.parse("VK_9");
    fun_VirtualKey_VKUnderscore9 = factory.makeAFun("_VirtualKey_VK_9", 0, false);

    pattern_VirtualKey_VKUnderscoreA = factory.parse("VK_A");
    fun_VirtualKey_VKUnderscoreA = factory.makeAFun("_VirtualKey_VK_A", 0, false);

    pattern_VirtualKey_VKUnderscoreB = factory.parse("VK_B");
    fun_VirtualKey_VKUnderscoreB = factory.makeAFun("_VirtualKey_VK_B", 0, false);

    pattern_VirtualKey_VKUnderscoreC = factory.parse("VK_C");
    fun_VirtualKey_VKUnderscoreC = factory.makeAFun("_VirtualKey_VK_C", 0, false);

    pattern_VirtualKey_VKUnderscoreD = factory.parse("VK_D");
    fun_VirtualKey_VKUnderscoreD = factory.makeAFun("_VirtualKey_VK_D", 0, false);

    pattern_VirtualKey_VKUnderscoreE = factory.parse("VK_E");
    fun_VirtualKey_VKUnderscoreE = factory.makeAFun("_VirtualKey_VK_E", 0, false);

    pattern_VirtualKey_VKUnderscoreF = factory.parse("VK_F");
    fun_VirtualKey_VKUnderscoreF = factory.makeAFun("_VirtualKey_VK_F", 0, false);

    pattern_VirtualKey_VKUnderscoreG = factory.parse("VK_G");
    fun_VirtualKey_VKUnderscoreG = factory.makeAFun("_VirtualKey_VK_G", 0, false);

    pattern_VirtualKey_VKUnderscoreH = factory.parse("VK_H");
    fun_VirtualKey_VKUnderscoreH = factory.makeAFun("_VirtualKey_VK_H", 0, false);

    pattern_VirtualKey_VKUnderscoreI = factory.parse("VK_I");
    fun_VirtualKey_VKUnderscoreI = factory.makeAFun("_VirtualKey_VK_I", 0, false);

    pattern_VirtualKey_VKUnderscoreJ = factory.parse("VK_J");
    fun_VirtualKey_VKUnderscoreJ = factory.makeAFun("_VirtualKey_VK_J", 0, false);

    pattern_VirtualKey_VKUnderscoreK = factory.parse("VK_K");
    fun_VirtualKey_VKUnderscoreK = factory.makeAFun("_VirtualKey_VK_K", 0, false);

    pattern_VirtualKey_VKUnderscoreL = factory.parse("VK_L");
    fun_VirtualKey_VKUnderscoreL = factory.makeAFun("_VirtualKey_VK_L", 0, false);

    pattern_VirtualKey_VKUnderscoreM = factory.parse("VK_M");
    fun_VirtualKey_VKUnderscoreM = factory.makeAFun("_VirtualKey_VK_M", 0, false);

    pattern_VirtualKey_VKUnderscoreN = factory.parse("VK_N");
    fun_VirtualKey_VKUnderscoreN = factory.makeAFun("_VirtualKey_VK_N", 0, false);

    pattern_VirtualKey_VKUnderscoreO = factory.parse("VK_O");
    fun_VirtualKey_VKUnderscoreO = factory.makeAFun("_VirtualKey_VK_O", 0, false);

    pattern_VirtualKey_VKUnderscoreP = factory.parse("VK_P");
    fun_VirtualKey_VKUnderscoreP = factory.makeAFun("_VirtualKey_VK_P", 0, false);

    pattern_VirtualKey_VKUnderscoreQ = factory.parse("VK_Q");
    fun_VirtualKey_VKUnderscoreQ = factory.makeAFun("_VirtualKey_VK_Q", 0, false);

    pattern_VirtualKey_VKUnderscoreR = factory.parse("VK_R");
    fun_VirtualKey_VKUnderscoreR = factory.makeAFun("_VirtualKey_VK_R", 0, false);

    pattern_VirtualKey_VKUnderscoreS = factory.parse("VK_S");
    fun_VirtualKey_VKUnderscoreS = factory.makeAFun("_VirtualKey_VK_S", 0, false);

    pattern_VirtualKey_VKUnderscoreT = factory.parse("VK_T");
    fun_VirtualKey_VKUnderscoreT = factory.makeAFun("_VirtualKey_VK_T", 0, false);

    pattern_VirtualKey_VKUnderscoreU = factory.parse("VK_U");
    fun_VirtualKey_VKUnderscoreU = factory.makeAFun("_VirtualKey_VK_U", 0, false);

    pattern_VirtualKey_VKUnderscoreV = factory.parse("VK_V");
    fun_VirtualKey_VKUnderscoreV = factory.makeAFun("_VirtualKey_VK_V", 0, false);

    pattern_VirtualKey_VKUnderscoreW = factory.parse("VK_W");
    fun_VirtualKey_VKUnderscoreW = factory.makeAFun("_VirtualKey_VK_W", 0, false);

    pattern_VirtualKey_VKUnderscoreX = factory.parse("VK_X");
    fun_VirtualKey_VKUnderscoreX = factory.makeAFun("_VirtualKey_VK_X", 0, false);

    pattern_VirtualKey_VKUnderscoreY = factory.parse("VK_Y");
    fun_VirtualKey_VKUnderscoreY = factory.makeAFun("_VirtualKey_VK_Y", 0, false);

    pattern_VirtualKey_VKUnderscoreZ = factory.parse("VK_Z");
    fun_VirtualKey_VKUnderscoreZ = factory.makeAFun("_VirtualKey_VK_Z", 0, false);

    pattern_VirtualKey_VKUnderscoreAMPERSAND = factory.parse("VK_AMPERSAND");
    fun_VirtualKey_VKUnderscoreAMPERSAND = factory.makeAFun("_VirtualKey_VK_AMPERSAND", 0, false);

    pattern_VirtualKey_VKUnderscoreASTERISK = factory.parse("VK_ASTERISK");
    fun_VirtualKey_VKUnderscoreASTERISK = factory.makeAFun("_VirtualKey_VK_ASTERISK", 0, false);

    pattern_VirtualKey_VKUnderscoreAT = factory.parse("VK_AT");
    fun_VirtualKey_VKUnderscoreAT = factory.makeAFun("_VirtualKey_VK_AT", 0, false);

    pattern_VirtualKey_VKUnderscoreBACKUnderscoreQUOTE = factory.parse("VK_BACK_QUOTE");
    fun_VirtualKey_VKUnderscoreBACKUnderscoreQUOTE = factory.makeAFun("_VirtualKey_VK_BACK_QUOTE", 0, false);

    pattern_VirtualKey_VKUnderscoreBACKUnderscoreSLASH = factory.parse("VK_BACK_SLASH");
    fun_VirtualKey_VKUnderscoreBACKUnderscoreSLASH = factory.makeAFun("_VirtualKey_VK_BACK_SLASH", 0, false);

    pattern_VirtualKey_VKUnderscoreBACKUnderscoreSPACE = factory.parse("VK_BACK_SPACE");
    fun_VirtualKey_VKUnderscoreBACKUnderscoreSPACE = factory.makeAFun("_VirtualKey_VK_BACK_SPACE", 0, false);

    pattern_VirtualKey_VKUnderscoreBEGIN = factory.parse("VK_BEGIN");
    fun_VirtualKey_VKUnderscoreBEGIN = factory.makeAFun("_VirtualKey_VK_BEGIN", 0, false);

    pattern_VirtualKey_VKUnderscoreBRACEUnderscoreLEFT = factory.parse("VK_BRACE_LEFT");
    fun_VirtualKey_VKUnderscoreBRACEUnderscoreLEFT = factory.makeAFun("_VirtualKey_VK_BRACE_LEFT", 0, false);

    pattern_VirtualKey_VKUnderscoreBRACEUnderscoreRIGHT = factory.parse("VK_BRACE_RIGHT");
    fun_VirtualKey_VKUnderscoreBRACEUnderscoreRIGHT = factory.makeAFun("_VirtualKey_VK_BRACE_RIGHT", 0, false);

    pattern_VirtualKey_VKUnderscoreCIRCUMFLEX = factory.parse("VK_CIRCUMFLEX");
    fun_VirtualKey_VKUnderscoreCIRCUMFLEX = factory.makeAFun("_VirtualKey_VK_CIRCUMFLEX", 0, false);

    pattern_VirtualKey_VKUnderscoreCLEAR = factory.parse("VK_CLEAR");
    fun_VirtualKey_VKUnderscoreCLEAR = factory.makeAFun("_VirtualKey_VK_CLEAR", 0, false);

    pattern_VirtualKey_VKUnderscoreCLOSEUnderscoreBRACKET = factory.parse("VK_CLOSE_BRACKET");
    fun_VirtualKey_VKUnderscoreCLOSEUnderscoreBRACKET = factory.makeAFun("_VirtualKey_VK_CLOSE_BRACKET", 0, false);

    pattern_VirtualKey_VKUnderscoreCOLON = factory.parse("VK_COLON");
    fun_VirtualKey_VKUnderscoreCOLON = factory.makeAFun("_VirtualKey_VK_COLON", 0, false);

    pattern_VirtualKey_VKUnderscoreCOMMA = factory.parse("VK_COMMA");
    fun_VirtualKey_VKUnderscoreCOMMA = factory.makeAFun("_VirtualKey_VK_COMMA", 0, false);

    pattern_VirtualKey_VKUnderscoreDECIMAL = factory.parse("VK_DECIMAL");
    fun_VirtualKey_VKUnderscoreDECIMAL = factory.makeAFun("_VirtualKey_VK_DECIMAL", 0, false);

    pattern_VirtualKey_VKUnderscoreDELETE = factory.parse("VK_DELETE");
    fun_VirtualKey_VKUnderscoreDELETE = factory.makeAFun("_VirtualKey_VK_DELETE", 0, false);

    pattern_VirtualKey_VKUnderscoreDIVIDE = factory.parse("VK_DIVIDE");
    fun_VirtualKey_VKUnderscoreDIVIDE = factory.makeAFun("_VirtualKey_VK_DIVIDE", 0, false);

    pattern_VirtualKey_VKUnderscoreDOLLAR = factory.parse("VK_DOLLAR");
    fun_VirtualKey_VKUnderscoreDOLLAR = factory.makeAFun("_VirtualKey_VK_DOLLAR", 0, false);

    pattern_VirtualKey_VKUnderscoreDOWN = factory.parse("VK_DOWN");
    fun_VirtualKey_VKUnderscoreDOWN = factory.makeAFun("_VirtualKey_VK_DOWN", 0, false);

    pattern_VirtualKey_VKUnderscoreEND = factory.parse("VK_END");
    fun_VirtualKey_VKUnderscoreEND = factory.makeAFun("_VirtualKey_VK_END", 0, false);

    pattern_VirtualKey_VKUnderscoreENTER = factory.parse("VK_ENTER");
    fun_VirtualKey_VKUnderscoreENTER = factory.makeAFun("_VirtualKey_VK_ENTER", 0, false);

    pattern_VirtualKey_VKUnderscoreEQUALS = factory.parse("VK_EQUALS");
    fun_VirtualKey_VKUnderscoreEQUALS = factory.makeAFun("_VirtualKey_VK_EQUALS", 0, false);

    pattern_VirtualKey_VKUnderscoreESCAPE = factory.parse("VK_ESCAPE");
    fun_VirtualKey_VKUnderscoreESCAPE = factory.makeAFun("_VirtualKey_VK_ESCAPE", 0, false);

    pattern_VirtualKey_VKUnderscoreEXCLAMATIONUnderscoreMARK = factory.parse("VK_EXCLAMATION_MARK");
    fun_VirtualKey_VKUnderscoreEXCLAMATIONUnderscoreMARK = factory.makeAFun("_VirtualKey_VK_EXCLAMATION_MARK", 0, false);

    pattern_VirtualKey_VKUnderscoreF1 = factory.parse("VK_F1");
    fun_VirtualKey_VKUnderscoreF1 = factory.makeAFun("_VirtualKey_VK_F1", 0, false);

    pattern_VirtualKey_VKUnderscoreF2 = factory.parse("VK_F2");
    fun_VirtualKey_VKUnderscoreF2 = factory.makeAFun("_VirtualKey_VK_F2", 0, false);

    pattern_VirtualKey_VKUnderscoreF3 = factory.parse("VK_F3");
    fun_VirtualKey_VKUnderscoreF3 = factory.makeAFun("_VirtualKey_VK_F3", 0, false);

    pattern_VirtualKey_VKUnderscoreF4 = factory.parse("VK_F4");
    fun_VirtualKey_VKUnderscoreF4 = factory.makeAFun("_VirtualKey_VK_F4", 0, false);

    pattern_VirtualKey_VKUnderscoreF5 = factory.parse("VK_F5");
    fun_VirtualKey_VKUnderscoreF5 = factory.makeAFun("_VirtualKey_VK_F5", 0, false);

    pattern_VirtualKey_VKUnderscoreF6 = factory.parse("VK_F6");
    fun_VirtualKey_VKUnderscoreF6 = factory.makeAFun("_VirtualKey_VK_F6", 0, false);

    pattern_VirtualKey_VKUnderscoreF7 = factory.parse("VK_F7");
    fun_VirtualKey_VKUnderscoreF7 = factory.makeAFun("_VirtualKey_VK_F7", 0, false);

    pattern_VirtualKey_VKUnderscoreF8 = factory.parse("VK_F8");
    fun_VirtualKey_VKUnderscoreF8 = factory.makeAFun("_VirtualKey_VK_F8", 0, false);

    pattern_VirtualKey_VKUnderscoreF9 = factory.parse("VK_F9");
    fun_VirtualKey_VKUnderscoreF9 = factory.makeAFun("_VirtualKey_VK_F9", 0, false);

    pattern_VirtualKey_VKUnderscoreF10 = factory.parse("VK_F10");
    fun_VirtualKey_VKUnderscoreF10 = factory.makeAFun("_VirtualKey_VK_F10", 0, false);

    pattern_VirtualKey_VKUnderscoreF11 = factory.parse("VK_F11");
    fun_VirtualKey_VKUnderscoreF11 = factory.makeAFun("_VirtualKey_VK_F11", 0, false);

    pattern_VirtualKey_VKUnderscoreF12 = factory.parse("VK_F12");
    fun_VirtualKey_VKUnderscoreF12 = factory.makeAFun("_VirtualKey_VK_F12", 0, false);

    pattern_VirtualKey_VKUnderscoreGREATER = factory.parse("VK_GREATER");
    fun_VirtualKey_VKUnderscoreGREATER = factory.makeAFun("_VirtualKey_VK_GREATER", 0, false);

    pattern_VirtualKey_VKUnderscoreHOME = factory.parse("VK_HOME");
    fun_VirtualKey_VKUnderscoreHOME = factory.makeAFun("_VirtualKey_VK_HOME", 0, false);

    pattern_VirtualKey_VKUnderscoreINSERT = factory.parse("VK_INSERT");
    fun_VirtualKey_VKUnderscoreINSERT = factory.makeAFun("_VirtualKey_VK_INSERT", 0, false);

    pattern_VirtualKey_VKUnderscoreLEFT = factory.parse("VK_LEFT");
    fun_VirtualKey_VKUnderscoreLEFT = factory.makeAFun("_VirtualKey_VK_LEFT", 0, false);

    pattern_VirtualKey_VKUnderscoreLEFTUnderscorePARENTHESIS = factory.parse("VK_LEFT_PARENTHESIS");
    fun_VirtualKey_VKUnderscoreLEFTUnderscorePARENTHESIS = factory.makeAFun("_VirtualKey_VK_LEFT_PARENTHESIS", 0, false);

    pattern_VirtualKey_VKUnderscoreMINUS = factory.parse("VK_MINUS");
    fun_VirtualKey_VKUnderscoreMINUS = factory.makeAFun("_VirtualKey_VK_MINUS", 0, false);

    pattern_VirtualKey_VKUnderscoreMULTIPLY = factory.parse("VK_MULTIPLY");
    fun_VirtualKey_VKUnderscoreMULTIPLY = factory.makeAFun("_VirtualKey_VK_MULTIPLY", 0, false);

    pattern_VirtualKey_VKUnderscoreNUMBERUnderscoreSIGN = factory.parse("VK_NUMBER_SIGN");
    fun_VirtualKey_VKUnderscoreNUMBERUnderscoreSIGN = factory.makeAFun("_VirtualKey_VK_NUMBER_SIGN", 0, false);

    pattern_VirtualKey_VKUnderscoreOPENUnderscoreBRACKET = factory.parse("VK_OPEN_BRACKET");
    fun_VirtualKey_VKUnderscoreOPENUnderscoreBRACKET = factory.makeAFun("_VirtualKey_VK_OPEN_BRACKET", 0, false);

    pattern_VirtualKey_VKUnderscorePAGEUnderscoreDOWN = factory.parse("VK_PAGE_DOWN");
    fun_VirtualKey_VKUnderscorePAGEUnderscoreDOWN = factory.makeAFun("_VirtualKey_VK_PAGE_DOWN", 0, false);

    pattern_VirtualKey_VKUnderscorePAGEUnderscoreUP = factory.parse("VK_PAGE_UP");
    fun_VirtualKey_VKUnderscorePAGEUnderscoreUP = factory.makeAFun("_VirtualKey_VK_PAGE_UP", 0, false);

    pattern_VirtualKey_VKUnderscorePAUSE = factory.parse("VK_PAUSE");
    fun_VirtualKey_VKUnderscorePAUSE = factory.makeAFun("_VirtualKey_VK_PAUSE", 0, false);

    pattern_VirtualKey_VKUnderscorePERIOD = factory.parse("VK_PERIOD");
    fun_VirtualKey_VKUnderscorePERIOD = factory.makeAFun("_VirtualKey_VK_PERIOD", 0, false);

    pattern_VirtualKey_VKUnderscorePLUS = factory.parse("VK_PLUS");
    fun_VirtualKey_VKUnderscorePLUS = factory.makeAFun("_VirtualKey_VK_PLUS", 0, false);

    pattern_VirtualKey_VKUnderscorePRINTSCREEN = factory.parse("VK_PRINTSCREEN");
    fun_VirtualKey_VKUnderscorePRINTSCREEN = factory.makeAFun("_VirtualKey_VK_PRINTSCREEN", 0, false);

    pattern_VirtualKey_VKUnderscoreQUOTE = factory.parse("VK_QUOTE");
    fun_VirtualKey_VKUnderscoreQUOTE = factory.makeAFun("_VirtualKey_VK_QUOTE", 0, false);

    pattern_VirtualKey_VKUnderscoreQUOTEDBL = factory.parse("VK_QUOTEDBL");
    fun_VirtualKey_VKUnderscoreQUOTEDBL = factory.makeAFun("_VirtualKey_VK_QUOTEDBL", 0, false);

    pattern_VirtualKey_VKUnderscoreRIGHT = factory.parse("VK_RIGHT");
    fun_VirtualKey_VKUnderscoreRIGHT = factory.makeAFun("_VirtualKey_VK_RIGHT", 0, false);

    pattern_VirtualKey_VKUnderscoreRIGHTUnderscorePARENTHESIS = factory.parse("VK_RIGHT_PARENTHESIS");
    fun_VirtualKey_VKUnderscoreRIGHTUnderscorePARENTHESIS = factory.makeAFun("_VirtualKey_VK_RIGHT_PARENTHESIS", 0, false);

    pattern_VirtualKey_VKUnderscoreSEMICOLON = factory.parse("VK_SEMICOLON");
    fun_VirtualKey_VKUnderscoreSEMICOLON = factory.makeAFun("_VirtualKey_VK_SEMICOLON", 0, false);

    pattern_VirtualKey_VKUnderscoreSLASH = factory.parse("VK_SLASH");
    fun_VirtualKey_VKUnderscoreSLASH = factory.makeAFun("_VirtualKey_VK_SLASH", 0, false);

    pattern_VirtualKey_VKUnderscoreSPACE = factory.parse("VK_SPACE");
    fun_VirtualKey_VKUnderscoreSPACE = factory.makeAFun("_VirtualKey_VK_SPACE", 0, false);

    pattern_VirtualKey_VKUnderscoreSUBTRACT = factory.parse("VK_SUBTRACT");
    fun_VirtualKey_VKUnderscoreSUBTRACT = factory.makeAFun("_VirtualKey_VK_SUBTRACT", 0, false);

    pattern_VirtualKey_VKUnderscoreTAB = factory.parse("VK_TAB");
    fun_VirtualKey_VKUnderscoreTAB = factory.makeAFun("_VirtualKey_VK_TAB", 0, false);

    pattern_VirtualKey_VKUnderscoreUNDERSCORE = factory.parse("VK_UNDERSCORE");
    fun_VirtualKey_VKUnderscoreUNDERSCORE = factory.makeAFun("_VirtualKey_VK_UNDERSCORE", 0, false);

    pattern_VirtualKey_VKUnderscoreUP = factory.parse("VK_UP");
    fun_VirtualKey_VKUnderscoreUP = factory.makeAFun("_VirtualKey_VK_UP", 0, false);

    pattern_Color_Rgb = factory.parse("rgb(<int>,<int>,<int>)");
    fun_Color_Rgb = factory.makeAFun("_Color_rgb", 3, false);

    pattern_Configuration_Configuration = factory.parse("configuration(<term>)");
    fun_Configuration_Configuration = factory.makeAFun("_Configuration_configuration", 1, false);

    pattern_Property_Import = factory.parse("import(<str>)");
    fun_Property_Import = factory.makeAFun("_Property_import", 1, false);

    pattern_Property_Script = factory.parse("script(<str>)");
    fun_Property_Script = factory.makeAFun("_Property_script", 1, false);

    pattern_Property_ScriptPath = factory.parse("script-path(<str>)");
    fun_Property_ScriptPath = factory.makeAFun("_Property_script-path", 1, false);

    pattern_Property_Action = factory.parse("action(<term>,<str>)");
    fun_Property_Action = factory.makeAFun("_Property_action", 2, false);

    pattern_Property_Editor = factory.parse("editor(<str>,<str>,<str>)");
    fun_Property_Editor = factory.makeAFun("_Property_editor", 3, false);

    pattern_Property_LibraryPath = factory.parse("library-path(<str>,<str>)");
    fun_Property_LibraryPath = factory.makeAFun("_Property_library-path", 2, false);

    pattern_Property_ModulePath = factory.parse("module-path(<str>,<str>)");
    fun_Property_ModulePath = factory.makeAFun("_Property_module-path", 2, false);

    pattern_Property_TextCategory = factory.parse("text-category(<term>,<term>)");
    fun_Property_TextCategory = factory.makeAFun("_Property_text-category", 2, false);

    pattern_ActionDescription_Description = factory.parse("description(<term>,<term>)");
    fun_ActionDescription_Description = factory.makeAFun("_ActionDescription_description", 2, false);

    pattern_Event_Popup = factory.parse("popup");
    fun_Event_Popup = factory.makeAFun("_Event_popup", 0, false);

    pattern_Event_Click = factory.parse("click(<term>,<term>)");
    fun_Event_Click = factory.makeAFun("_Event_click", 2, false);

    pattern_Event_Icon = factory.parse("icon(<str>,<str>)");
    fun_Event_Icon = factory.makeAFun("_Event_icon", 2, false);

    pattern_Event_Menu = factory.parse("menu(<term>,<str>)");
    fun_Event_Menu = factory.makeAFun("_Event_menu", 2, false);

    pattern_Event_MenuShortcut = factory.parse("menu-shortcut(<term>,<term>,<str>)");
    fun_Event_MenuShortcut = factory.makeAFun("_Event_menu-shortcut", 3, false);

    pattern_Item_Label = factory.parse("label(<str>)");
    fun_Item_Label = factory.makeAFun("_Item_label", 1, false);

    pattern_TextCategoryName_Focus = factory.parse("focus");
    fun_TextCategoryName_Focus = factory.makeAFun("_TextCategoryName_focus", 0, false);

    pattern_TextCategoryName_Selection = factory.parse("selection");
    fun_TextCategoryName_Selection = factory.makeAFun("_TextCategoryName_selection", 0, false);

    pattern_TextCategoryName_Normal = factory.parse("normal");
    fun_TextCategoryName_Normal = factory.makeAFun("_TextCategoryName_normal", 0, false);

    pattern_TextCategoryName_Extern = factory.parse("extern(<str>)");
    fun_TextCategoryName_Extern = factory.makeAFun("_TextCategoryName_extern", 1, false);

    pattern_TextAttribute_ForegroundColor = factory.parse("foreground-color(<term>)");
    fun_TextAttribute_ForegroundColor = factory.makeAFun("_TextAttribute_foreground-color", 1, false);

    pattern_TextAttribute_BackgroundColor = factory.parse("background-color(<term>)");
    fun_TextAttribute_BackgroundColor = factory.makeAFun("_TextAttribute_background-color", 1, false);

    pattern_TextAttribute_Style = factory.parse("style(<term>)");
    fun_TextAttribute_Style = factory.makeAFun("_TextAttribute_style", 1, false);

    pattern_TextAttribute_Font = factory.parse("font(<str>)");
    fun_TextAttribute_Font = factory.makeAFun("_TextAttribute_font", 1, false);

    pattern_TextAttribute_Size = factory.parse("size(<int>)");
    fun_TextAttribute_Size = factory.makeAFun("_TextAttribute_size", 1, false);

    pattern_ShortCut_Shortcut = factory.parse("shortcut(<term>,<term>)");
    fun_ShortCut_Shortcut = factory.makeAFun("_ShortCut_shortcut", 2, false);

    pattern_TextStyle_Bold = factory.parse("bold");
    fun_TextStyle_Bold = factory.makeAFun("_TextStyle_bold", 0, false);

    pattern_TextStyle_Italics = factory.parse("italics");
    fun_TextStyle_Italics = factory.makeAFun("_TextStyle_italics", 0, false);

    pattern_TextStyle_Underlined = factory.parse("underlined");
    fun_TextStyle_Underlined = factory.makeAFun("_TextStyle_underlined", 0, false);

    empty_PropertyList = (nl.cwi.sen1.configapi.types.PropertyList) factory.build(new nl.cwi.sen1.configapi.types.PropertyList(this, factory.getEmpty(), null, null));
    empty_ActionDescriptionList = (nl.cwi.sen1.configapi.types.ActionDescriptionList) factory.build(new nl.cwi.sen1.configapi.types.ActionDescriptionList(this, factory.getEmpty(), null, null));
    empty_TextAttributeMap = (nl.cwi.sen1.configapi.types.TextAttributeMap) factory.build(new nl.cwi.sen1.configapi.types.TextAttributeMap(this, factory.getEmpty(), null, null));
    empty_KeyModifierList = (nl.cwi.sen1.configapi.types.KeyModifierList) factory.build(new nl.cwi.sen1.configapi.types.KeyModifierList(this, factory.getEmpty(), null, null));
    empty_ItemLabels = (nl.cwi.sen1.configapi.types.ItemLabels) factory.build(new nl.cwi.sen1.configapi.types.ItemLabels(this, factory.getEmpty(), null, null));
  }

/*genAlternativeMethods*/
  public nl.cwi.sen1.configapi.types.virtualbutton.NOBUTTON makeVirtualButton_NOBUTTON(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualbutton.NOBUTTON) factory.build( new nl.cwi.sen1.configapi.types.virtualbutton.NOBUTTON(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualbutton.NOBUTTON makeVirtualButton_NOBUTTON() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualButton_NOBUTTON(fun_VirtualButton_NOBUTTON, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualButton VirtualButton_NOBUTTONFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualButton_NOBUTTON);

    if (children != null) {
      return makeVirtualButton_NOBUTTON(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualbutton.NOBUTTON arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualButton_NOBUTTON, args);
  }

  public nl.cwi.sen1.configapi.types.virtualbutton.BUTTON1 makeVirtualButton_BUTTON1(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualbutton.BUTTON1) factory.build( new nl.cwi.sen1.configapi.types.virtualbutton.BUTTON1(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualbutton.BUTTON1 makeVirtualButton_BUTTON1() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualButton_BUTTON1(fun_VirtualButton_BUTTON1, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualButton VirtualButton_BUTTON1FromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualButton_BUTTON1);

    if (children != null) {
      return makeVirtualButton_BUTTON1(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualbutton.BUTTON1 arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualButton_BUTTON1, args);
  }

  public nl.cwi.sen1.configapi.types.virtualbutton.BUTTON2 makeVirtualButton_BUTTON2(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualbutton.BUTTON2) factory.build( new nl.cwi.sen1.configapi.types.virtualbutton.BUTTON2(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualbutton.BUTTON2 makeVirtualButton_BUTTON2() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualButton_BUTTON2(fun_VirtualButton_BUTTON2, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualButton VirtualButton_BUTTON2FromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualButton_BUTTON2);

    if (children != null) {
      return makeVirtualButton_BUTTON2(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualbutton.BUTTON2 arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualButton_BUTTON2, args);
  }

  public nl.cwi.sen1.configapi.types.virtualbutton.BUTTON3 makeVirtualButton_BUTTON3(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualbutton.BUTTON3) factory.build( new nl.cwi.sen1.configapi.types.virtualbutton.BUTTON3(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualbutton.BUTTON3 makeVirtualButton_BUTTON3() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualButton_BUTTON3(fun_VirtualButton_BUTTON3, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualButton VirtualButton_BUTTON3FromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualButton_BUTTON3);

    if (children != null) {
      return makeVirtualButton_BUTTON3(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualbutton.BUTTON3 arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualButton_BUTTON3, args);
  }

  public nl.cwi.sen1.configapi.types.keymodifier.MUnderscoreALT makeKeyModifier_MUnderscoreALT(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.keymodifier.MUnderscoreALT) factory.build( new nl.cwi.sen1.configapi.types.keymodifier.MUnderscoreALT(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.keymodifier.MUnderscoreALT makeKeyModifier_MUnderscoreALT() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeKeyModifier_MUnderscoreALT(fun_KeyModifier_MUnderscoreALT, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.KeyModifier KeyModifier_MUnderscoreALTFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_KeyModifier_MUnderscoreALT);

    if (children != null) {
      return makeKeyModifier_MUnderscoreALT(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.keymodifier.MUnderscoreALT arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_KeyModifier_MUnderscoreALT, args);
  }

  public nl.cwi.sen1.configapi.types.keymodifier.MUnderscoreCTRL makeKeyModifier_MUnderscoreCTRL(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.keymodifier.MUnderscoreCTRL) factory.build( new nl.cwi.sen1.configapi.types.keymodifier.MUnderscoreCTRL(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.keymodifier.MUnderscoreCTRL makeKeyModifier_MUnderscoreCTRL() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeKeyModifier_MUnderscoreCTRL(fun_KeyModifier_MUnderscoreCTRL, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.KeyModifier KeyModifier_MUnderscoreCTRLFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_KeyModifier_MUnderscoreCTRL);

    if (children != null) {
      return makeKeyModifier_MUnderscoreCTRL(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.keymodifier.MUnderscoreCTRL arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_KeyModifier_MUnderscoreCTRL, args);
  }

  public nl.cwi.sen1.configapi.types.keymodifier.MUnderscoreSHIFT makeKeyModifier_MUnderscoreSHIFT(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.keymodifier.MUnderscoreSHIFT) factory.build( new nl.cwi.sen1.configapi.types.keymodifier.MUnderscoreSHIFT(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.keymodifier.MUnderscoreSHIFT makeKeyModifier_MUnderscoreSHIFT() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeKeyModifier_MUnderscoreSHIFT(fun_KeyModifier_MUnderscoreSHIFT, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.KeyModifier KeyModifier_MUnderscoreSHIFTFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_KeyModifier_MUnderscoreSHIFT);

    if (children != null) {
      return makeKeyModifier_MUnderscoreSHIFT(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.keymodifier.MUnderscoreSHIFT arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_KeyModifier_MUnderscoreSHIFT, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscore0 makeVirtualKey_VKUnderscore0(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscore0) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscore0(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscore0 makeVirtualKey_VKUnderscore0() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscore0(fun_VirtualKey_VKUnderscore0, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscore0FromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscore0);

    if (children != null) {
      return makeVirtualKey_VKUnderscore0(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscore0 arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscore0, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscore1 makeVirtualKey_VKUnderscore1(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscore1) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscore1(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscore1 makeVirtualKey_VKUnderscore1() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscore1(fun_VirtualKey_VKUnderscore1, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscore1FromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscore1);

    if (children != null) {
      return makeVirtualKey_VKUnderscore1(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscore1 arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscore1, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscore2 makeVirtualKey_VKUnderscore2(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscore2) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscore2(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscore2 makeVirtualKey_VKUnderscore2() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscore2(fun_VirtualKey_VKUnderscore2, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscore2FromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscore2);

    if (children != null) {
      return makeVirtualKey_VKUnderscore2(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscore2 arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscore2, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscore3 makeVirtualKey_VKUnderscore3(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscore3) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscore3(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscore3 makeVirtualKey_VKUnderscore3() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscore3(fun_VirtualKey_VKUnderscore3, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscore3FromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscore3);

    if (children != null) {
      return makeVirtualKey_VKUnderscore3(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscore3 arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscore3, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscore4 makeVirtualKey_VKUnderscore4(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscore4) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscore4(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscore4 makeVirtualKey_VKUnderscore4() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscore4(fun_VirtualKey_VKUnderscore4, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscore4FromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscore4);

    if (children != null) {
      return makeVirtualKey_VKUnderscore4(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscore4 arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscore4, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscore5 makeVirtualKey_VKUnderscore5(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscore5) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscore5(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscore5 makeVirtualKey_VKUnderscore5() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscore5(fun_VirtualKey_VKUnderscore5, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscore5FromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscore5);

    if (children != null) {
      return makeVirtualKey_VKUnderscore5(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscore5 arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscore5, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscore6 makeVirtualKey_VKUnderscore6(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscore6) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscore6(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscore6 makeVirtualKey_VKUnderscore6() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscore6(fun_VirtualKey_VKUnderscore6, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscore6FromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscore6);

    if (children != null) {
      return makeVirtualKey_VKUnderscore6(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscore6 arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscore6, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscore7 makeVirtualKey_VKUnderscore7(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscore7) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscore7(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscore7 makeVirtualKey_VKUnderscore7() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscore7(fun_VirtualKey_VKUnderscore7, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscore7FromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscore7);

    if (children != null) {
      return makeVirtualKey_VKUnderscore7(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscore7 arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscore7, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscore8 makeVirtualKey_VKUnderscore8(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscore8) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscore8(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscore8 makeVirtualKey_VKUnderscore8() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscore8(fun_VirtualKey_VKUnderscore8, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscore8FromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscore8);

    if (children != null) {
      return makeVirtualKey_VKUnderscore8(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscore8 arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscore8, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscore9 makeVirtualKey_VKUnderscore9(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscore9) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscore9(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscore9 makeVirtualKey_VKUnderscore9() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscore9(fun_VirtualKey_VKUnderscore9, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscore9FromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscore9);

    if (children != null) {
      return makeVirtualKey_VKUnderscore9(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscore9 arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscore9, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreA makeVirtualKey_VKUnderscoreA(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreA) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreA(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreA makeVirtualKey_VKUnderscoreA() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreA(fun_VirtualKey_VKUnderscoreA, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreAFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreA);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreA(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreA arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreA, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreB makeVirtualKey_VKUnderscoreB(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreB) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreB(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreB makeVirtualKey_VKUnderscoreB() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreB(fun_VirtualKey_VKUnderscoreB, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreBFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreB);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreB(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreB arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreB, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreC makeVirtualKey_VKUnderscoreC(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreC) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreC(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreC makeVirtualKey_VKUnderscoreC() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreC(fun_VirtualKey_VKUnderscoreC, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreCFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreC);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreC(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreC arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreC, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreD makeVirtualKey_VKUnderscoreD(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreD) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreD(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreD makeVirtualKey_VKUnderscoreD() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreD(fun_VirtualKey_VKUnderscoreD, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreDFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreD);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreD(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreD arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreD, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreE makeVirtualKey_VKUnderscoreE(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreE) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreE(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreE makeVirtualKey_VKUnderscoreE() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreE(fun_VirtualKey_VKUnderscoreE, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreEFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreE);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreE(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreE arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreE, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF makeVirtualKey_VKUnderscoreF(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF makeVirtualKey_VKUnderscoreF() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreF(fun_VirtualKey_VKUnderscoreF, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreFFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreF);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreF(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreF, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreG makeVirtualKey_VKUnderscoreG(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreG) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreG(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreG makeVirtualKey_VKUnderscoreG() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreG(fun_VirtualKey_VKUnderscoreG, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreGFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreG);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreG(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreG arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreG, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreH makeVirtualKey_VKUnderscoreH(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreH) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreH(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreH makeVirtualKey_VKUnderscoreH() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreH(fun_VirtualKey_VKUnderscoreH, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreHFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreH);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreH(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreH arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreH, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreI makeVirtualKey_VKUnderscoreI(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreI) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreI(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreI makeVirtualKey_VKUnderscoreI() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreI(fun_VirtualKey_VKUnderscoreI, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreIFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreI);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreI(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreI arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreI, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreJ makeVirtualKey_VKUnderscoreJ(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreJ) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreJ(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreJ makeVirtualKey_VKUnderscoreJ() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreJ(fun_VirtualKey_VKUnderscoreJ, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreJFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreJ);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreJ(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreJ arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreJ, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreK makeVirtualKey_VKUnderscoreK(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreK) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreK(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreK makeVirtualKey_VKUnderscoreK() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreK(fun_VirtualKey_VKUnderscoreK, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreKFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreK);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreK(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreK arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreK, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreL makeVirtualKey_VKUnderscoreL(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreL) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreL(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreL makeVirtualKey_VKUnderscoreL() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreL(fun_VirtualKey_VKUnderscoreL, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreLFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreL);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreL(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreL arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreL, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreM makeVirtualKey_VKUnderscoreM(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreM) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreM(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreM makeVirtualKey_VKUnderscoreM() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreM(fun_VirtualKey_VKUnderscoreM, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreMFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreM);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreM(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreM arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreM, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreN makeVirtualKey_VKUnderscoreN(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreN) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreN(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreN makeVirtualKey_VKUnderscoreN() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreN(fun_VirtualKey_VKUnderscoreN, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreNFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreN);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreN(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreN arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreN, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreO makeVirtualKey_VKUnderscoreO(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreO) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreO(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreO makeVirtualKey_VKUnderscoreO() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreO(fun_VirtualKey_VKUnderscoreO, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreOFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreO);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreO(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreO arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreO, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreP makeVirtualKey_VKUnderscoreP(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreP) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreP(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreP makeVirtualKey_VKUnderscoreP() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreP(fun_VirtualKey_VKUnderscoreP, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscorePFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreP);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreP(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreP arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreP, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreQ makeVirtualKey_VKUnderscoreQ(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreQ) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreQ(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreQ makeVirtualKey_VKUnderscoreQ() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreQ(fun_VirtualKey_VKUnderscoreQ, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreQFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreQ);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreQ(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreQ arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreQ, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreR makeVirtualKey_VKUnderscoreR(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreR) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreR(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreR makeVirtualKey_VKUnderscoreR() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreR(fun_VirtualKey_VKUnderscoreR, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreRFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreR);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreR(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreR arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreR, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreS makeVirtualKey_VKUnderscoreS(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreS) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreS(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreS makeVirtualKey_VKUnderscoreS() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreS(fun_VirtualKey_VKUnderscoreS, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreSFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreS);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreS(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreS arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreS, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreT makeVirtualKey_VKUnderscoreT(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreT) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreT(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreT makeVirtualKey_VKUnderscoreT() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreT(fun_VirtualKey_VKUnderscoreT, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreTFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreT);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreT(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreT arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreT, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreU makeVirtualKey_VKUnderscoreU(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreU) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreU(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreU makeVirtualKey_VKUnderscoreU() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreU(fun_VirtualKey_VKUnderscoreU, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreUFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreU);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreU(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreU arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreU, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreV makeVirtualKey_VKUnderscoreV(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreV) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreV(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreV makeVirtualKey_VKUnderscoreV() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreV(fun_VirtualKey_VKUnderscoreV, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreVFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreV);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreV(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreV arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreV, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreW makeVirtualKey_VKUnderscoreW(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreW) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreW(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreW makeVirtualKey_VKUnderscoreW() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreW(fun_VirtualKey_VKUnderscoreW, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreWFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreW);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreW(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreW arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreW, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreX makeVirtualKey_VKUnderscoreX(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreX) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreX(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreX makeVirtualKey_VKUnderscoreX() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreX(fun_VirtualKey_VKUnderscoreX, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreXFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreX);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreX(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreX arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreX, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreY makeVirtualKey_VKUnderscoreY(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreY) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreY(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreY makeVirtualKey_VKUnderscoreY() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreY(fun_VirtualKey_VKUnderscoreY, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreYFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreY);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreY(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreY arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreY, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreZ makeVirtualKey_VKUnderscoreZ(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreZ) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreZ(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreZ makeVirtualKey_VKUnderscoreZ() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreZ(fun_VirtualKey_VKUnderscoreZ, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreZFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreZ);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreZ(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreZ arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreZ, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreAMPERSAND makeVirtualKey_VKUnderscoreAMPERSAND(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreAMPERSAND) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreAMPERSAND(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreAMPERSAND makeVirtualKey_VKUnderscoreAMPERSAND() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreAMPERSAND(fun_VirtualKey_VKUnderscoreAMPERSAND, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreAMPERSANDFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreAMPERSAND);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreAMPERSAND(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreAMPERSAND arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreAMPERSAND, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreASTERISK makeVirtualKey_VKUnderscoreASTERISK(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreASTERISK) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreASTERISK(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreASTERISK makeVirtualKey_VKUnderscoreASTERISK() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreASTERISK(fun_VirtualKey_VKUnderscoreASTERISK, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreASTERISKFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreASTERISK);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreASTERISK(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreASTERISK arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreASTERISK, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreAT makeVirtualKey_VKUnderscoreAT(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreAT) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreAT(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreAT makeVirtualKey_VKUnderscoreAT() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreAT(fun_VirtualKey_VKUnderscoreAT, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreATFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreAT);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreAT(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreAT arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreAT, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreBACKUnderscoreQUOTE makeVirtualKey_VKUnderscoreBACKUnderscoreQUOTE(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreBACKUnderscoreQUOTE) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreBACKUnderscoreQUOTE(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreBACKUnderscoreQUOTE makeVirtualKey_VKUnderscoreBACKUnderscoreQUOTE() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreBACKUnderscoreQUOTE(fun_VirtualKey_VKUnderscoreBACKUnderscoreQUOTE, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreBACKUnderscoreQUOTEFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreBACKUnderscoreQUOTE);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreBACKUnderscoreQUOTE(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreBACKUnderscoreQUOTE arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreBACKUnderscoreQUOTE, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreBACKUnderscoreSLASH makeVirtualKey_VKUnderscoreBACKUnderscoreSLASH(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreBACKUnderscoreSLASH) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreBACKUnderscoreSLASH(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreBACKUnderscoreSLASH makeVirtualKey_VKUnderscoreBACKUnderscoreSLASH() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreBACKUnderscoreSLASH(fun_VirtualKey_VKUnderscoreBACKUnderscoreSLASH, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreBACKUnderscoreSLASHFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreBACKUnderscoreSLASH);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreBACKUnderscoreSLASH(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreBACKUnderscoreSLASH arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreBACKUnderscoreSLASH, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreBACKUnderscoreSPACE makeVirtualKey_VKUnderscoreBACKUnderscoreSPACE(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreBACKUnderscoreSPACE) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreBACKUnderscoreSPACE(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreBACKUnderscoreSPACE makeVirtualKey_VKUnderscoreBACKUnderscoreSPACE() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreBACKUnderscoreSPACE(fun_VirtualKey_VKUnderscoreBACKUnderscoreSPACE, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreBACKUnderscoreSPACEFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreBACKUnderscoreSPACE);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreBACKUnderscoreSPACE(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreBACKUnderscoreSPACE arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreBACKUnderscoreSPACE, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreBEGIN makeVirtualKey_VKUnderscoreBEGIN(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreBEGIN) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreBEGIN(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreBEGIN makeVirtualKey_VKUnderscoreBEGIN() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreBEGIN(fun_VirtualKey_VKUnderscoreBEGIN, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreBEGINFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreBEGIN);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreBEGIN(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreBEGIN arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreBEGIN, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreBRACEUnderscoreLEFT makeVirtualKey_VKUnderscoreBRACEUnderscoreLEFT(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreBRACEUnderscoreLEFT) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreBRACEUnderscoreLEFT(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreBRACEUnderscoreLEFT makeVirtualKey_VKUnderscoreBRACEUnderscoreLEFT() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreBRACEUnderscoreLEFT(fun_VirtualKey_VKUnderscoreBRACEUnderscoreLEFT, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreBRACEUnderscoreLEFTFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreBRACEUnderscoreLEFT);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreBRACEUnderscoreLEFT(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreBRACEUnderscoreLEFT arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreBRACEUnderscoreLEFT, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreBRACEUnderscoreRIGHT makeVirtualKey_VKUnderscoreBRACEUnderscoreRIGHT(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreBRACEUnderscoreRIGHT) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreBRACEUnderscoreRIGHT(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreBRACEUnderscoreRIGHT makeVirtualKey_VKUnderscoreBRACEUnderscoreRIGHT() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreBRACEUnderscoreRIGHT(fun_VirtualKey_VKUnderscoreBRACEUnderscoreRIGHT, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreBRACEUnderscoreRIGHTFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreBRACEUnderscoreRIGHT);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreBRACEUnderscoreRIGHT(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreBRACEUnderscoreRIGHT arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreBRACEUnderscoreRIGHT, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreCIRCUMFLEX makeVirtualKey_VKUnderscoreCIRCUMFLEX(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreCIRCUMFLEX) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreCIRCUMFLEX(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreCIRCUMFLEX makeVirtualKey_VKUnderscoreCIRCUMFLEX() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreCIRCUMFLEX(fun_VirtualKey_VKUnderscoreCIRCUMFLEX, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreCIRCUMFLEXFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreCIRCUMFLEX);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreCIRCUMFLEX(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreCIRCUMFLEX arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreCIRCUMFLEX, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreCLEAR makeVirtualKey_VKUnderscoreCLEAR(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreCLEAR) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreCLEAR(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreCLEAR makeVirtualKey_VKUnderscoreCLEAR() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreCLEAR(fun_VirtualKey_VKUnderscoreCLEAR, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreCLEARFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreCLEAR);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreCLEAR(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreCLEAR arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreCLEAR, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreCLOSEUnderscoreBRACKET makeVirtualKey_VKUnderscoreCLOSEUnderscoreBRACKET(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreCLOSEUnderscoreBRACKET) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreCLOSEUnderscoreBRACKET(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreCLOSEUnderscoreBRACKET makeVirtualKey_VKUnderscoreCLOSEUnderscoreBRACKET() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreCLOSEUnderscoreBRACKET(fun_VirtualKey_VKUnderscoreCLOSEUnderscoreBRACKET, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreCLOSEUnderscoreBRACKETFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreCLOSEUnderscoreBRACKET);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreCLOSEUnderscoreBRACKET(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreCLOSEUnderscoreBRACKET arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreCLOSEUnderscoreBRACKET, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreCOLON makeVirtualKey_VKUnderscoreCOLON(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreCOLON) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreCOLON(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreCOLON makeVirtualKey_VKUnderscoreCOLON() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreCOLON(fun_VirtualKey_VKUnderscoreCOLON, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreCOLONFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreCOLON);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreCOLON(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreCOLON arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreCOLON, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreCOMMA makeVirtualKey_VKUnderscoreCOMMA(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreCOMMA) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreCOMMA(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreCOMMA makeVirtualKey_VKUnderscoreCOMMA() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreCOMMA(fun_VirtualKey_VKUnderscoreCOMMA, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreCOMMAFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreCOMMA);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreCOMMA(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreCOMMA arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreCOMMA, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreDECIMAL makeVirtualKey_VKUnderscoreDECIMAL(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreDECIMAL) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreDECIMAL(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreDECIMAL makeVirtualKey_VKUnderscoreDECIMAL() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreDECIMAL(fun_VirtualKey_VKUnderscoreDECIMAL, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreDECIMALFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreDECIMAL);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreDECIMAL(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreDECIMAL arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreDECIMAL, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreDELETE makeVirtualKey_VKUnderscoreDELETE(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreDELETE) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreDELETE(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreDELETE makeVirtualKey_VKUnderscoreDELETE() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreDELETE(fun_VirtualKey_VKUnderscoreDELETE, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreDELETEFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreDELETE);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreDELETE(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreDELETE arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreDELETE, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreDIVIDE makeVirtualKey_VKUnderscoreDIVIDE(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreDIVIDE) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreDIVIDE(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreDIVIDE makeVirtualKey_VKUnderscoreDIVIDE() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreDIVIDE(fun_VirtualKey_VKUnderscoreDIVIDE, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreDIVIDEFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreDIVIDE);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreDIVIDE(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreDIVIDE arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreDIVIDE, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreDOLLAR makeVirtualKey_VKUnderscoreDOLLAR(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreDOLLAR) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreDOLLAR(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreDOLLAR makeVirtualKey_VKUnderscoreDOLLAR() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreDOLLAR(fun_VirtualKey_VKUnderscoreDOLLAR, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreDOLLARFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreDOLLAR);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreDOLLAR(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreDOLLAR arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreDOLLAR, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreDOWN makeVirtualKey_VKUnderscoreDOWN(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreDOWN) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreDOWN(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreDOWN makeVirtualKey_VKUnderscoreDOWN() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreDOWN(fun_VirtualKey_VKUnderscoreDOWN, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreDOWNFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreDOWN);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreDOWN(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreDOWN arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreDOWN, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreEND makeVirtualKey_VKUnderscoreEND(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreEND) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreEND(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreEND makeVirtualKey_VKUnderscoreEND() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreEND(fun_VirtualKey_VKUnderscoreEND, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreENDFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreEND);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreEND(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreEND arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreEND, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreENTER makeVirtualKey_VKUnderscoreENTER(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreENTER) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreENTER(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreENTER makeVirtualKey_VKUnderscoreENTER() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreENTER(fun_VirtualKey_VKUnderscoreENTER, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreENTERFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreENTER);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreENTER(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreENTER arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreENTER, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreEQUALS makeVirtualKey_VKUnderscoreEQUALS(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreEQUALS) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreEQUALS(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreEQUALS makeVirtualKey_VKUnderscoreEQUALS() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreEQUALS(fun_VirtualKey_VKUnderscoreEQUALS, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreEQUALSFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreEQUALS);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreEQUALS(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreEQUALS arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreEQUALS, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreESCAPE makeVirtualKey_VKUnderscoreESCAPE(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreESCAPE) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreESCAPE(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreESCAPE makeVirtualKey_VKUnderscoreESCAPE() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreESCAPE(fun_VirtualKey_VKUnderscoreESCAPE, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreESCAPEFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreESCAPE);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreESCAPE(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreESCAPE arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreESCAPE, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreEXCLAMATIONUnderscoreMARK makeVirtualKey_VKUnderscoreEXCLAMATIONUnderscoreMARK(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreEXCLAMATIONUnderscoreMARK) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreEXCLAMATIONUnderscoreMARK(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreEXCLAMATIONUnderscoreMARK makeVirtualKey_VKUnderscoreEXCLAMATIONUnderscoreMARK() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreEXCLAMATIONUnderscoreMARK(fun_VirtualKey_VKUnderscoreEXCLAMATIONUnderscoreMARK, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreEXCLAMATIONUnderscoreMARKFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreEXCLAMATIONUnderscoreMARK);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreEXCLAMATIONUnderscoreMARK(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreEXCLAMATIONUnderscoreMARK arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreEXCLAMATIONUnderscoreMARK, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF1 makeVirtualKey_VKUnderscoreF1(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF1) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF1(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF1 makeVirtualKey_VKUnderscoreF1() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreF1(fun_VirtualKey_VKUnderscoreF1, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreF1FromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreF1);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreF1(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF1 arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreF1, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF2 makeVirtualKey_VKUnderscoreF2(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF2) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF2(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF2 makeVirtualKey_VKUnderscoreF2() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreF2(fun_VirtualKey_VKUnderscoreF2, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreF2FromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreF2);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreF2(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF2 arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreF2, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF3 makeVirtualKey_VKUnderscoreF3(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF3) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF3(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF3 makeVirtualKey_VKUnderscoreF3() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreF3(fun_VirtualKey_VKUnderscoreF3, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreF3FromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreF3);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreF3(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF3 arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreF3, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF4 makeVirtualKey_VKUnderscoreF4(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF4) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF4(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF4 makeVirtualKey_VKUnderscoreF4() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreF4(fun_VirtualKey_VKUnderscoreF4, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreF4FromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreF4);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreF4(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF4 arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreF4, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF5 makeVirtualKey_VKUnderscoreF5(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF5) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF5(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF5 makeVirtualKey_VKUnderscoreF5() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreF5(fun_VirtualKey_VKUnderscoreF5, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreF5FromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreF5);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreF5(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF5 arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreF5, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF6 makeVirtualKey_VKUnderscoreF6(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF6) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF6(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF6 makeVirtualKey_VKUnderscoreF6() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreF6(fun_VirtualKey_VKUnderscoreF6, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreF6FromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreF6);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreF6(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF6 arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreF6, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF7 makeVirtualKey_VKUnderscoreF7(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF7) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF7(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF7 makeVirtualKey_VKUnderscoreF7() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreF7(fun_VirtualKey_VKUnderscoreF7, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreF7FromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreF7);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreF7(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF7 arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreF7, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF8 makeVirtualKey_VKUnderscoreF8(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF8) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF8(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF8 makeVirtualKey_VKUnderscoreF8() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreF8(fun_VirtualKey_VKUnderscoreF8, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreF8FromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreF8);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreF8(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF8 arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreF8, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF9 makeVirtualKey_VKUnderscoreF9(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF9) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF9(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF9 makeVirtualKey_VKUnderscoreF9() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreF9(fun_VirtualKey_VKUnderscoreF9, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreF9FromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreF9);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreF9(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF9 arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreF9, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF10 makeVirtualKey_VKUnderscoreF10(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF10) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF10(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF10 makeVirtualKey_VKUnderscoreF10() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreF10(fun_VirtualKey_VKUnderscoreF10, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreF10FromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreF10);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreF10(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF10 arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreF10, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF11 makeVirtualKey_VKUnderscoreF11(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF11) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF11(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF11 makeVirtualKey_VKUnderscoreF11() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreF11(fun_VirtualKey_VKUnderscoreF11, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreF11FromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreF11);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreF11(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF11 arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreF11, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF12 makeVirtualKey_VKUnderscoreF12(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF12) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF12(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF12 makeVirtualKey_VKUnderscoreF12() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreF12(fun_VirtualKey_VKUnderscoreF12, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreF12FromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreF12);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreF12(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreF12 arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreF12, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreGREATER makeVirtualKey_VKUnderscoreGREATER(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreGREATER) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreGREATER(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreGREATER makeVirtualKey_VKUnderscoreGREATER() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreGREATER(fun_VirtualKey_VKUnderscoreGREATER, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreGREATERFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreGREATER);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreGREATER(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreGREATER arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreGREATER, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreHOME makeVirtualKey_VKUnderscoreHOME(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreHOME) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreHOME(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreHOME makeVirtualKey_VKUnderscoreHOME() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreHOME(fun_VirtualKey_VKUnderscoreHOME, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreHOMEFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreHOME);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreHOME(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreHOME arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreHOME, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreINSERT makeVirtualKey_VKUnderscoreINSERT(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreINSERT) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreINSERT(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreINSERT makeVirtualKey_VKUnderscoreINSERT() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreINSERT(fun_VirtualKey_VKUnderscoreINSERT, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreINSERTFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreINSERT);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreINSERT(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreINSERT arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreINSERT, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreLEFT makeVirtualKey_VKUnderscoreLEFT(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreLEFT) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreLEFT(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreLEFT makeVirtualKey_VKUnderscoreLEFT() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreLEFT(fun_VirtualKey_VKUnderscoreLEFT, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreLEFTFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreLEFT);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreLEFT(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreLEFT arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreLEFT, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreLEFTUnderscorePARENTHESIS makeVirtualKey_VKUnderscoreLEFTUnderscorePARENTHESIS(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreLEFTUnderscorePARENTHESIS) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreLEFTUnderscorePARENTHESIS(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreLEFTUnderscorePARENTHESIS makeVirtualKey_VKUnderscoreLEFTUnderscorePARENTHESIS() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreLEFTUnderscorePARENTHESIS(fun_VirtualKey_VKUnderscoreLEFTUnderscorePARENTHESIS, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreLEFTUnderscorePARENTHESISFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreLEFTUnderscorePARENTHESIS);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreLEFTUnderscorePARENTHESIS(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreLEFTUnderscorePARENTHESIS arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreLEFTUnderscorePARENTHESIS, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreMINUS makeVirtualKey_VKUnderscoreMINUS(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreMINUS) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreMINUS(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreMINUS makeVirtualKey_VKUnderscoreMINUS() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreMINUS(fun_VirtualKey_VKUnderscoreMINUS, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreMINUSFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreMINUS);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreMINUS(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreMINUS arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreMINUS, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreMULTIPLY makeVirtualKey_VKUnderscoreMULTIPLY(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreMULTIPLY) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreMULTIPLY(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreMULTIPLY makeVirtualKey_VKUnderscoreMULTIPLY() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreMULTIPLY(fun_VirtualKey_VKUnderscoreMULTIPLY, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreMULTIPLYFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreMULTIPLY);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreMULTIPLY(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreMULTIPLY arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreMULTIPLY, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreNUMBERUnderscoreSIGN makeVirtualKey_VKUnderscoreNUMBERUnderscoreSIGN(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreNUMBERUnderscoreSIGN) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreNUMBERUnderscoreSIGN(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreNUMBERUnderscoreSIGN makeVirtualKey_VKUnderscoreNUMBERUnderscoreSIGN() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreNUMBERUnderscoreSIGN(fun_VirtualKey_VKUnderscoreNUMBERUnderscoreSIGN, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreNUMBERUnderscoreSIGNFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreNUMBERUnderscoreSIGN);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreNUMBERUnderscoreSIGN(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreNUMBERUnderscoreSIGN arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreNUMBERUnderscoreSIGN, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreOPENUnderscoreBRACKET makeVirtualKey_VKUnderscoreOPENUnderscoreBRACKET(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreOPENUnderscoreBRACKET) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreOPENUnderscoreBRACKET(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreOPENUnderscoreBRACKET makeVirtualKey_VKUnderscoreOPENUnderscoreBRACKET() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreOPENUnderscoreBRACKET(fun_VirtualKey_VKUnderscoreOPENUnderscoreBRACKET, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreOPENUnderscoreBRACKETFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreOPENUnderscoreBRACKET);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreOPENUnderscoreBRACKET(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreOPENUnderscoreBRACKET arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreOPENUnderscoreBRACKET, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscorePAGEUnderscoreDOWN makeVirtualKey_VKUnderscorePAGEUnderscoreDOWN(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscorePAGEUnderscoreDOWN) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscorePAGEUnderscoreDOWN(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscorePAGEUnderscoreDOWN makeVirtualKey_VKUnderscorePAGEUnderscoreDOWN() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscorePAGEUnderscoreDOWN(fun_VirtualKey_VKUnderscorePAGEUnderscoreDOWN, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscorePAGEUnderscoreDOWNFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscorePAGEUnderscoreDOWN);

    if (children != null) {
      return makeVirtualKey_VKUnderscorePAGEUnderscoreDOWN(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscorePAGEUnderscoreDOWN arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscorePAGEUnderscoreDOWN, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscorePAGEUnderscoreUP makeVirtualKey_VKUnderscorePAGEUnderscoreUP(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscorePAGEUnderscoreUP) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscorePAGEUnderscoreUP(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscorePAGEUnderscoreUP makeVirtualKey_VKUnderscorePAGEUnderscoreUP() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscorePAGEUnderscoreUP(fun_VirtualKey_VKUnderscorePAGEUnderscoreUP, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscorePAGEUnderscoreUPFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscorePAGEUnderscoreUP);

    if (children != null) {
      return makeVirtualKey_VKUnderscorePAGEUnderscoreUP(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscorePAGEUnderscoreUP arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscorePAGEUnderscoreUP, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscorePAUSE makeVirtualKey_VKUnderscorePAUSE(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscorePAUSE) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscorePAUSE(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscorePAUSE makeVirtualKey_VKUnderscorePAUSE() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscorePAUSE(fun_VirtualKey_VKUnderscorePAUSE, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscorePAUSEFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscorePAUSE);

    if (children != null) {
      return makeVirtualKey_VKUnderscorePAUSE(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscorePAUSE arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscorePAUSE, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscorePERIOD makeVirtualKey_VKUnderscorePERIOD(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscorePERIOD) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscorePERIOD(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscorePERIOD makeVirtualKey_VKUnderscorePERIOD() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscorePERIOD(fun_VirtualKey_VKUnderscorePERIOD, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscorePERIODFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscorePERIOD);

    if (children != null) {
      return makeVirtualKey_VKUnderscorePERIOD(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscorePERIOD arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscorePERIOD, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscorePLUS makeVirtualKey_VKUnderscorePLUS(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscorePLUS) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscorePLUS(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscorePLUS makeVirtualKey_VKUnderscorePLUS() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscorePLUS(fun_VirtualKey_VKUnderscorePLUS, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscorePLUSFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscorePLUS);

    if (children != null) {
      return makeVirtualKey_VKUnderscorePLUS(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscorePLUS arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscorePLUS, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscorePRINTSCREEN makeVirtualKey_VKUnderscorePRINTSCREEN(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscorePRINTSCREEN) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscorePRINTSCREEN(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscorePRINTSCREEN makeVirtualKey_VKUnderscorePRINTSCREEN() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscorePRINTSCREEN(fun_VirtualKey_VKUnderscorePRINTSCREEN, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscorePRINTSCREENFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscorePRINTSCREEN);

    if (children != null) {
      return makeVirtualKey_VKUnderscorePRINTSCREEN(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscorePRINTSCREEN arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscorePRINTSCREEN, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreQUOTE makeVirtualKey_VKUnderscoreQUOTE(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreQUOTE) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreQUOTE(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreQUOTE makeVirtualKey_VKUnderscoreQUOTE() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreQUOTE(fun_VirtualKey_VKUnderscoreQUOTE, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreQUOTEFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreQUOTE);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreQUOTE(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreQUOTE arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreQUOTE, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreQUOTEDBL makeVirtualKey_VKUnderscoreQUOTEDBL(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreQUOTEDBL) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreQUOTEDBL(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreQUOTEDBL makeVirtualKey_VKUnderscoreQUOTEDBL() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreQUOTEDBL(fun_VirtualKey_VKUnderscoreQUOTEDBL, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreQUOTEDBLFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreQUOTEDBL);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreQUOTEDBL(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreQUOTEDBL arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreQUOTEDBL, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreRIGHT makeVirtualKey_VKUnderscoreRIGHT(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreRIGHT) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreRIGHT(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreRIGHT makeVirtualKey_VKUnderscoreRIGHT() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreRIGHT(fun_VirtualKey_VKUnderscoreRIGHT, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreRIGHTFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreRIGHT);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreRIGHT(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreRIGHT arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreRIGHT, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreRIGHTUnderscorePARENTHESIS makeVirtualKey_VKUnderscoreRIGHTUnderscorePARENTHESIS(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreRIGHTUnderscorePARENTHESIS) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreRIGHTUnderscorePARENTHESIS(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreRIGHTUnderscorePARENTHESIS makeVirtualKey_VKUnderscoreRIGHTUnderscorePARENTHESIS() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreRIGHTUnderscorePARENTHESIS(fun_VirtualKey_VKUnderscoreRIGHTUnderscorePARENTHESIS, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreRIGHTUnderscorePARENTHESISFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreRIGHTUnderscorePARENTHESIS);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreRIGHTUnderscorePARENTHESIS(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreRIGHTUnderscorePARENTHESIS arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreRIGHTUnderscorePARENTHESIS, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreSEMICOLON makeVirtualKey_VKUnderscoreSEMICOLON(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreSEMICOLON) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreSEMICOLON(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreSEMICOLON makeVirtualKey_VKUnderscoreSEMICOLON() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreSEMICOLON(fun_VirtualKey_VKUnderscoreSEMICOLON, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreSEMICOLONFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreSEMICOLON);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreSEMICOLON(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreSEMICOLON arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreSEMICOLON, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreSLASH makeVirtualKey_VKUnderscoreSLASH(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreSLASH) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreSLASH(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreSLASH makeVirtualKey_VKUnderscoreSLASH() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreSLASH(fun_VirtualKey_VKUnderscoreSLASH, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreSLASHFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreSLASH);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreSLASH(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreSLASH arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreSLASH, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreSPACE makeVirtualKey_VKUnderscoreSPACE(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreSPACE) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreSPACE(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreSPACE makeVirtualKey_VKUnderscoreSPACE() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreSPACE(fun_VirtualKey_VKUnderscoreSPACE, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreSPACEFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreSPACE);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreSPACE(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreSPACE arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreSPACE, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreSUBTRACT makeVirtualKey_VKUnderscoreSUBTRACT(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreSUBTRACT) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreSUBTRACT(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreSUBTRACT makeVirtualKey_VKUnderscoreSUBTRACT() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreSUBTRACT(fun_VirtualKey_VKUnderscoreSUBTRACT, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreSUBTRACTFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreSUBTRACT);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreSUBTRACT(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreSUBTRACT arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreSUBTRACT, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreTAB makeVirtualKey_VKUnderscoreTAB(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreTAB) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreTAB(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreTAB makeVirtualKey_VKUnderscoreTAB() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreTAB(fun_VirtualKey_VKUnderscoreTAB, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreTABFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreTAB);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreTAB(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreTAB arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreTAB, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreUNDERSCORE makeVirtualKey_VKUnderscoreUNDERSCORE(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreUNDERSCORE) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreUNDERSCORE(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreUNDERSCORE makeVirtualKey_VKUnderscoreUNDERSCORE() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreUNDERSCORE(fun_VirtualKey_VKUnderscoreUNDERSCORE, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreUNDERSCOREFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreUNDERSCORE);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreUNDERSCORE(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreUNDERSCORE arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreUNDERSCORE, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreUP makeVirtualKey_VKUnderscoreUP(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreUP) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreUP(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreUP makeVirtualKey_VKUnderscoreUP() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VKUnderscoreUP(fun_VirtualKey_VKUnderscoreUP, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VKUnderscoreUPFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VKUnderscoreUP);

    if (children != null) {
      return makeVirtualKey_VKUnderscoreUP(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VKUnderscoreUP arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VKUnderscoreUP, args);
  }

  public nl.cwi.sen1.configapi.types.color.Rgb makeColor_Rgb(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.color.Rgb) factory.build( new nl.cwi.sen1.configapi.types.color.Rgb(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.color.Rgb makeColor_Rgb(int _red, int _green, int _blue) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeInt(_red), factory.makeInt(_green), factory.makeInt(_blue)};
    return makeColor_Rgb(fun_Color_Rgb, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.Color Color_RgbFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Color_Rgb);

    if (children != null) {
      return makeColor_Rgb(
        ((Integer) children.get(0)).intValue(),
        ((Integer) children.get(1)).intValue(),
        ((Integer) children.get(2)).intValue()
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.color.Rgb arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(new Integer(arg.getRed()));
    args.add(new Integer(arg.getGreen()));
    args.add(new Integer(arg.getBlue()));
    return factory.make(pattern_Color_Rgb, args);
  }

  public nl.cwi.sen1.configapi.types.configuration.Configuration makeConfiguration_Configuration(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.configuration.Configuration) factory.build( new nl.cwi.sen1.configapi.types.configuration.Configuration(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.configuration.Configuration makeConfiguration_Configuration(nl.cwi.sen1.configapi.types.PropertyList _list) {
    aterm.ATerm[] args = new aterm.ATerm[] {_list};
    return makeConfiguration_Configuration(fun_Configuration_Configuration, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.Configuration Configuration_ConfigurationFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Configuration_Configuration);

    if (children != null) {
      return makeConfiguration_Configuration(
        PropertyListFromTerm((aterm.ATerm) children.get(0))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.configuration.Configuration arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getList().toTerm());
    return factory.make(pattern_Configuration_Configuration, args);
  }

  public nl.cwi.sen1.configapi.types.property.Import makeProperty_Import(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.property.Import) factory.build( new nl.cwi.sen1.configapi.types.property.Import(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.property.Import makeProperty_Import(String _path) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeAppl(factory.makeAFun(_path, 0, true))};
    return makeProperty_Import(fun_Property_Import, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.Property Property_ImportFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Property_Import);

    if (children != null) {
      return makeProperty_Import(
        (String) children.get(0)
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.property.Import arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getPath());
    return factory.make(pattern_Property_Import, args);
  }

  public nl.cwi.sen1.configapi.types.property.Script makeProperty_Script(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.property.Script) factory.build( new nl.cwi.sen1.configapi.types.property.Script(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.property.Script makeProperty_Script(String _path) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeAppl(factory.makeAFun(_path, 0, true))};
    return makeProperty_Script(fun_Property_Script, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.Property Property_ScriptFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Property_Script);

    if (children != null) {
      return makeProperty_Script(
        (String) children.get(0)
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.property.Script arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getPath());
    return factory.make(pattern_Property_Script, args);
  }

  public nl.cwi.sen1.configapi.types.property.ScriptPath makeProperty_ScriptPath(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.property.ScriptPath) factory.build( new nl.cwi.sen1.configapi.types.property.ScriptPath(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.property.ScriptPath makeProperty_ScriptPath(String _path) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeAppl(factory.makeAFun(_path, 0, true))};
    return makeProperty_ScriptPath(fun_Property_ScriptPath, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.Property Property_ScriptPathFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Property_ScriptPath);

    if (children != null) {
      return makeProperty_ScriptPath(
        (String) children.get(0)
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.property.ScriptPath arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getPath());
    return factory.make(pattern_Property_ScriptPath, args);
  }

  public nl.cwi.sen1.configapi.types.property.Action makeProperty_Action(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.property.Action) factory.build( new nl.cwi.sen1.configapi.types.property.Action(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.property.Action makeProperty_Action(nl.cwi.sen1.configapi.types.ActionDescriptionList _list, String _action) {
    aterm.ATerm[] args = new aterm.ATerm[] {_list, factory.makeAppl(factory.makeAFun(_action, 0, true))};
    return makeProperty_Action(fun_Property_Action, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.Property Property_ActionFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Property_Action);

    if (children != null) {
      return makeProperty_Action(
        ActionDescriptionListFromTerm((aterm.ATerm) children.get(0)),
        (String) children.get(1)
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.property.Action arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getList().toTerm());
    args.add(arg.getAction());
    return factory.make(pattern_Property_Action, args);
  }

  public nl.cwi.sen1.configapi.types.property.Editor makeProperty_Editor(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.property.Editor) factory.build( new nl.cwi.sen1.configapi.types.property.Editor(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.property.Editor makeProperty_Editor(String _editor, String _language, String _extension) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeAppl(factory.makeAFun(_editor, 0, true)), factory.makeAppl(factory.makeAFun(_language, 0, true)), factory.makeAppl(factory.makeAFun(_extension, 0, true))};
    return makeProperty_Editor(fun_Property_Editor, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.Property Property_EditorFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Property_Editor);

    if (children != null) {
      return makeProperty_Editor(
        (String) children.get(0),
        (String) children.get(1),
        (String) children.get(2)
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.property.Editor arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getEditor());
    args.add(arg.getLanguage());
    args.add(arg.getExtension());
    return factory.make(pattern_Property_Editor, args);
  }

  public nl.cwi.sen1.configapi.types.property.LibraryPath makeProperty_LibraryPath(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.property.LibraryPath) factory.build( new nl.cwi.sen1.configapi.types.property.LibraryPath(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.property.LibraryPath makeProperty_LibraryPath(String _label, String _path) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeAppl(factory.makeAFun(_label, 0, true)), factory.makeAppl(factory.makeAFun(_path, 0, true))};
    return makeProperty_LibraryPath(fun_Property_LibraryPath, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.Property Property_LibraryPathFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Property_LibraryPath);

    if (children != null) {
      return makeProperty_LibraryPath(
        (String) children.get(0),
        (String) children.get(1)
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.property.LibraryPath arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getLabel());
    args.add(arg.getPath());
    return factory.make(pattern_Property_LibraryPath, args);
  }

  public nl.cwi.sen1.configapi.types.property.ModulePath makeProperty_ModulePath(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.property.ModulePath) factory.build( new nl.cwi.sen1.configapi.types.property.ModulePath(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.property.ModulePath makeProperty_ModulePath(String _label, String _path) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeAppl(factory.makeAFun(_label, 0, true)), factory.makeAppl(factory.makeAFun(_path, 0, true))};
    return makeProperty_ModulePath(fun_Property_ModulePath, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.Property Property_ModulePathFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Property_ModulePath);

    if (children != null) {
      return makeProperty_ModulePath(
        (String) children.get(0),
        (String) children.get(1)
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.property.ModulePath arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getLabel());
    args.add(arg.getPath());
    return factory.make(pattern_Property_ModulePath, args);
  }

  public nl.cwi.sen1.configapi.types.property.TextCategory makeProperty_TextCategory(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.property.TextCategory) factory.build( new nl.cwi.sen1.configapi.types.property.TextCategory(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.property.TextCategory makeProperty_TextCategory(nl.cwi.sen1.configapi.types.TextCategoryName _category, nl.cwi.sen1.configapi.types.TextAttributeMap _map) {
    aterm.ATerm[] args = new aterm.ATerm[] {_category, _map};
    return makeProperty_TextCategory(fun_Property_TextCategory, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.Property Property_TextCategoryFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Property_TextCategory);

    if (children != null) {
      return makeProperty_TextCategory(
        TextCategoryNameFromTerm((aterm.ATerm) children.get(0)),
        TextAttributeMapFromTerm((aterm.ATerm) children.get(1))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.property.TextCategory arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getCategory().toTerm());
    args.add(arg.getMap().toTerm());
    return factory.make(pattern_Property_TextCategory, args);
  }

  public nl.cwi.sen1.configapi.types.actiondescription.Description makeActionDescription_Description(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.actiondescription.Description) factory.build( new nl.cwi.sen1.configapi.types.actiondescription.Description(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.actiondescription.Description makeActionDescription_Description(aterm.ATerm _context, nl.cwi.sen1.configapi.types.Event _event) {
    aterm.ATerm[] args = new aterm.ATerm[] {_context, _event};
    return makeActionDescription_Description(fun_ActionDescription_Description, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.ActionDescription ActionDescription_DescriptionFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_ActionDescription_Description);

    if (children != null) {
      return makeActionDescription_Description(
        (aterm.ATerm) children.get(0),
        EventFromTerm((aterm.ATerm) children.get(1))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.actiondescription.Description arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getContext());
    args.add(arg.getEvent().toTerm());
    return factory.make(pattern_ActionDescription_Description, args);
  }

  public nl.cwi.sen1.configapi.types.event.Popup makeEvent_Popup(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.event.Popup) factory.build( new nl.cwi.sen1.configapi.types.event.Popup(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.event.Popup makeEvent_Popup() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeEvent_Popup(fun_Event_Popup, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.Event Event_PopupFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Event_Popup);

    if (children != null) {
      return makeEvent_Popup(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.event.Popup arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_Event_Popup, args);
  }

  public nl.cwi.sen1.configapi.types.event.Click makeEvent_Click(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.event.Click) factory.build( new nl.cwi.sen1.configapi.types.event.Click(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.event.Click makeEvent_Click(nl.cwi.sen1.configapi.types.KeyModifierList _list, nl.cwi.sen1.configapi.types.VirtualButton _button) {
    aterm.ATerm[] args = new aterm.ATerm[] {_list, _button};
    return makeEvent_Click(fun_Event_Click, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.Event Event_ClickFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Event_Click);

    if (children != null) {
      return makeEvent_Click(
        KeyModifierListFromTerm((aterm.ATerm) children.get(0)),
        VirtualButtonFromTerm((aterm.ATerm) children.get(1))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.event.Click arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getList().toTerm());
    args.add(arg.getButton().toTerm());
    return factory.make(pattern_Event_Click, args);
  }

  public nl.cwi.sen1.configapi.types.event.Icon makeEvent_Icon(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.event.Icon) factory.build( new nl.cwi.sen1.configapi.types.event.Icon(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.event.Icon makeEvent_Icon(String _title, String _path) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeAppl(factory.makeAFun(_title, 0, true)), factory.makeAppl(factory.makeAFun(_path, 0, true))};
    return makeEvent_Icon(fun_Event_Icon, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.Event Event_IconFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Event_Icon);

    if (children != null) {
      return makeEvent_Icon(
        (String) children.get(0),
        (String) children.get(1)
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.event.Icon arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getTitle());
    args.add(arg.getPath());
    return factory.make(pattern_Event_Icon, args);
  }

  public nl.cwi.sen1.configapi.types.event.Menu makeEvent_Menu(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.event.Menu) factory.build( new nl.cwi.sen1.configapi.types.event.Menu(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.event.Menu makeEvent_Menu(nl.cwi.sen1.configapi.types.ItemLabels _labels, String _info) {
    aterm.ATerm[] args = new aterm.ATerm[] {_labels, factory.makeAppl(factory.makeAFun(_info, 0, true))};
    return makeEvent_Menu(fun_Event_Menu, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.Event Event_MenuFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Event_Menu);

    if (children != null) {
      return makeEvent_Menu(
        ItemLabelsFromTerm((aterm.ATerm) children.get(0)),
        (String) children.get(1)
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.event.Menu arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getLabels().toTerm());
    args.add(arg.getInfo());
    return factory.make(pattern_Event_Menu, args);
  }

  public nl.cwi.sen1.configapi.types.event.MenuShortcut makeEvent_MenuShortcut(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.event.MenuShortcut) factory.build( new nl.cwi.sen1.configapi.types.event.MenuShortcut(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.event.MenuShortcut makeEvent_MenuShortcut(nl.cwi.sen1.configapi.types.ItemLabels _labels, nl.cwi.sen1.configapi.types.ShortCut _shortcut, String _info) {
    aterm.ATerm[] args = new aterm.ATerm[] {_labels, _shortcut, factory.makeAppl(factory.makeAFun(_info, 0, true))};
    return makeEvent_MenuShortcut(fun_Event_MenuShortcut, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.Event Event_MenuShortcutFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Event_MenuShortcut);

    if (children != null) {
      return makeEvent_MenuShortcut(
        ItemLabelsFromTerm((aterm.ATerm) children.get(0)),
        ShortCutFromTerm((aterm.ATerm) children.get(1)),
        (String) children.get(2)
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.event.MenuShortcut arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getLabels().toTerm());
    args.add(arg.getShortcut().toTerm());
    args.add(arg.getInfo());
    return factory.make(pattern_Event_MenuShortcut, args);
  }

  public nl.cwi.sen1.configapi.types.item.Label makeItem_Label(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.item.Label) factory.build( new nl.cwi.sen1.configapi.types.item.Label(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.item.Label makeItem_Label(String _name) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeAppl(factory.makeAFun(_name, 0, true))};
    return makeItem_Label(fun_Item_Label, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.Item Item_LabelFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_Item_Label);

    if (children != null) {
      return makeItem_Label(
        (String) children.get(0)
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.item.Label arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getName());
    return factory.make(pattern_Item_Label, args);
  }

  public nl.cwi.sen1.configapi.types.textcategoryname.Focus makeTextCategoryName_Focus(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.textcategoryname.Focus) factory.build( new nl.cwi.sen1.configapi.types.textcategoryname.Focus(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.textcategoryname.Focus makeTextCategoryName_Focus() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeTextCategoryName_Focus(fun_TextCategoryName_Focus, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.TextCategoryName TextCategoryName_FocusFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_TextCategoryName_Focus);

    if (children != null) {
      return makeTextCategoryName_Focus(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.textcategoryname.Focus arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_TextCategoryName_Focus, args);
  }

  public nl.cwi.sen1.configapi.types.textcategoryname.Selection makeTextCategoryName_Selection(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.textcategoryname.Selection) factory.build( new nl.cwi.sen1.configapi.types.textcategoryname.Selection(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.textcategoryname.Selection makeTextCategoryName_Selection() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeTextCategoryName_Selection(fun_TextCategoryName_Selection, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.TextCategoryName TextCategoryName_SelectionFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_TextCategoryName_Selection);

    if (children != null) {
      return makeTextCategoryName_Selection(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.textcategoryname.Selection arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_TextCategoryName_Selection, args);
  }

  public nl.cwi.sen1.configapi.types.textcategoryname.Normal makeTextCategoryName_Normal(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.textcategoryname.Normal) factory.build( new nl.cwi.sen1.configapi.types.textcategoryname.Normal(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.textcategoryname.Normal makeTextCategoryName_Normal() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeTextCategoryName_Normal(fun_TextCategoryName_Normal, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.TextCategoryName TextCategoryName_NormalFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_TextCategoryName_Normal);

    if (children != null) {
      return makeTextCategoryName_Normal(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.textcategoryname.Normal arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_TextCategoryName_Normal, args);
  }

  public nl.cwi.sen1.configapi.types.textcategoryname.Extern makeTextCategoryName_Extern(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.textcategoryname.Extern) factory.build( new nl.cwi.sen1.configapi.types.textcategoryname.Extern(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.textcategoryname.Extern makeTextCategoryName_Extern(String _name) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeAppl(factory.makeAFun(_name, 0, true))};
    return makeTextCategoryName_Extern(fun_TextCategoryName_Extern, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.TextCategoryName TextCategoryName_ExternFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_TextCategoryName_Extern);

    if (children != null) {
      return makeTextCategoryName_Extern(
        (String) children.get(0)
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.textcategoryname.Extern arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getName());
    return factory.make(pattern_TextCategoryName_Extern, args);
  }

  public nl.cwi.sen1.configapi.types.textattribute.ForegroundColor makeTextAttribute_ForegroundColor(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.textattribute.ForegroundColor) factory.build( new nl.cwi.sen1.configapi.types.textattribute.ForegroundColor(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.textattribute.ForegroundColor makeTextAttribute_ForegroundColor(nl.cwi.sen1.configapi.types.Color _color) {
    aterm.ATerm[] args = new aterm.ATerm[] {_color};
    return makeTextAttribute_ForegroundColor(fun_TextAttribute_ForegroundColor, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.TextAttribute TextAttribute_ForegroundColorFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_TextAttribute_ForegroundColor);

    if (children != null) {
      return makeTextAttribute_ForegroundColor(
        ColorFromTerm((aterm.ATerm) children.get(0))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.textattribute.ForegroundColor arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getColor().toTerm());
    return factory.make(pattern_TextAttribute_ForegroundColor, args);
  }

  public nl.cwi.sen1.configapi.types.textattribute.BackgroundColor makeTextAttribute_BackgroundColor(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.textattribute.BackgroundColor) factory.build( new nl.cwi.sen1.configapi.types.textattribute.BackgroundColor(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.textattribute.BackgroundColor makeTextAttribute_BackgroundColor(nl.cwi.sen1.configapi.types.Color _color) {
    aterm.ATerm[] args = new aterm.ATerm[] {_color};
    return makeTextAttribute_BackgroundColor(fun_TextAttribute_BackgroundColor, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.TextAttribute TextAttribute_BackgroundColorFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_TextAttribute_BackgroundColor);

    if (children != null) {
      return makeTextAttribute_BackgroundColor(
        ColorFromTerm((aterm.ATerm) children.get(0))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.textattribute.BackgroundColor arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getColor().toTerm());
    return factory.make(pattern_TextAttribute_BackgroundColor, args);
  }

  public nl.cwi.sen1.configapi.types.textattribute.Style makeTextAttribute_Style(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.textattribute.Style) factory.build( new nl.cwi.sen1.configapi.types.textattribute.Style(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.textattribute.Style makeTextAttribute_Style(nl.cwi.sen1.configapi.types.TextStyle _style) {
    aterm.ATerm[] args = new aterm.ATerm[] {_style};
    return makeTextAttribute_Style(fun_TextAttribute_Style, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.TextAttribute TextAttribute_StyleFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_TextAttribute_Style);

    if (children != null) {
      return makeTextAttribute_Style(
        TextStyleFromTerm((aterm.ATerm) children.get(0))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.textattribute.Style arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getStyle().toTerm());
    return factory.make(pattern_TextAttribute_Style, args);
  }

  public nl.cwi.sen1.configapi.types.textattribute.Font makeTextAttribute_Font(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.textattribute.Font) factory.build( new nl.cwi.sen1.configapi.types.textattribute.Font(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.textattribute.Font makeTextAttribute_Font(String _name) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeAppl(factory.makeAFun(_name, 0, true))};
    return makeTextAttribute_Font(fun_TextAttribute_Font, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.TextAttribute TextAttribute_FontFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_TextAttribute_Font);

    if (children != null) {
      return makeTextAttribute_Font(
        (String) children.get(0)
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.textattribute.Font arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getName());
    return factory.make(pattern_TextAttribute_Font, args);
  }

  public nl.cwi.sen1.configapi.types.textattribute.Size makeTextAttribute_Size(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.textattribute.Size) factory.build( new nl.cwi.sen1.configapi.types.textattribute.Size(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.textattribute.Size makeTextAttribute_Size(int _point) {
    aterm.ATerm[] args = new aterm.ATerm[] {factory.makeInt(_point)};
    return makeTextAttribute_Size(fun_TextAttribute_Size, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.TextAttribute TextAttribute_SizeFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_TextAttribute_Size);

    if (children != null) {
      return makeTextAttribute_Size(
        ((Integer) children.get(0)).intValue()
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.textattribute.Size arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(new Integer(arg.getPoint()));
    return factory.make(pattern_TextAttribute_Size, args);
  }

  public nl.cwi.sen1.configapi.types.shortcut.Shortcut makeShortCut_Shortcut(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.shortcut.Shortcut) factory.build( new nl.cwi.sen1.configapi.types.shortcut.Shortcut(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.shortcut.Shortcut makeShortCut_Shortcut(nl.cwi.sen1.configapi.types.KeyModifierList _list, nl.cwi.sen1.configapi.types.VirtualKey _key) {
    aterm.ATerm[] args = new aterm.ATerm[] {_list, _key};
    return makeShortCut_Shortcut(fun_ShortCut_Shortcut, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.ShortCut ShortCut_ShortcutFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_ShortCut_Shortcut);

    if (children != null) {
      return makeShortCut_Shortcut(
        KeyModifierListFromTerm((aterm.ATerm) children.get(0)),
        VirtualKeyFromTerm((aterm.ATerm) children.get(1))
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.shortcut.Shortcut arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    args.add(arg.getList().toTerm());
    args.add(arg.getKey().toTerm());
    return factory.make(pattern_ShortCut_Shortcut, args);
  }

  public nl.cwi.sen1.configapi.types.textstyle.Bold makeTextStyle_Bold(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.textstyle.Bold) factory.build( new nl.cwi.sen1.configapi.types.textstyle.Bold(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.textstyle.Bold makeTextStyle_Bold() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeTextStyle_Bold(fun_TextStyle_Bold, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.TextStyle TextStyle_BoldFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_TextStyle_Bold);

    if (children != null) {
      return makeTextStyle_Bold(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.textstyle.Bold arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_TextStyle_Bold, args);
  }

  public nl.cwi.sen1.configapi.types.textstyle.Italics makeTextStyle_Italics(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.textstyle.Italics) factory.build( new nl.cwi.sen1.configapi.types.textstyle.Italics(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.textstyle.Italics makeTextStyle_Italics() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeTextStyle_Italics(fun_TextStyle_Italics, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.TextStyle TextStyle_ItalicsFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_TextStyle_Italics);

    if (children != null) {
      return makeTextStyle_Italics(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.textstyle.Italics arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_TextStyle_Italics, args);
  }

  public nl.cwi.sen1.configapi.types.textstyle.Underlined makeTextStyle_Underlined(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.textstyle.Underlined) factory.build( new nl.cwi.sen1.configapi.types.textstyle.Underlined(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.textstyle.Underlined makeTextStyle_Underlined() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeTextStyle_Underlined(fun_TextStyle_Underlined, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.TextStyle TextStyle_UnderlinedFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_TextStyle_Underlined);

    if (children != null) {
      return makeTextStyle_Underlined(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.textstyle.Underlined arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_TextStyle_Underlined, args);
  }

/*genMakeLists*/
  public nl.cwi.sen1.configapi.types.PropertyList makePropertyList() {
    return empty_PropertyList;
  }

  public nl.cwi.sen1.configapi.types.PropertyList makePropertyList(nl.cwi.sen1.configapi.types.Property elem) {
    return makePropertyList(elem, empty_PropertyList);
  }

  public nl.cwi.sen1.configapi.types.PropertyList makePropertyList(nl.cwi.sen1.configapi.types.Property head, nl.cwi.sen1.configapi.types.PropertyList tail) {
    return makePropertyList(head, tail, factory.getEmpty());
  }

  public nl.cwi.sen1.configapi.types.PropertyList makePropertyList(aterm.ATerm head, aterm.ATermList tail, aterm.ATermList annos) {
      return (nl.cwi.sen1.configapi.types.PropertyList) factory.build(new nl.cwi.sen1.configapi.types.PropertyList(this, annos, head, tail));
  }

  public nl.cwi.sen1.configapi.types.PropertyList makePropertyList(nl.cwi.sen1.configapi.types.Property elem0, nl.cwi.sen1.configapi.types.Property elem1) {
    return makePropertyList(elem0, makePropertyList(elem1));
  }

  public nl.cwi.sen1.configapi.types.PropertyList makePropertyList(nl.cwi.sen1.configapi.types.Property elem0, nl.cwi.sen1.configapi.types.Property elem1, nl.cwi.sen1.configapi.types.Property elem2) {
    return makePropertyList(elem0, makePropertyList(elem1, elem2));
  }

  public nl.cwi.sen1.configapi.types.PropertyList makePropertyList(nl.cwi.sen1.configapi.types.Property elem0, nl.cwi.sen1.configapi.types.Property elem1, nl.cwi.sen1.configapi.types.Property elem2, nl.cwi.sen1.configapi.types.Property elem3) {
    return makePropertyList(elem0, makePropertyList(elem1, elem2, elem3));
  }

  public nl.cwi.sen1.configapi.types.PropertyList makePropertyList(nl.cwi.sen1.configapi.types.Property elem0, nl.cwi.sen1.configapi.types.Property elem1, nl.cwi.sen1.configapi.types.Property elem2, nl.cwi.sen1.configapi.types.Property elem3, nl.cwi.sen1.configapi.types.Property elem4) {
    return makePropertyList(elem0, makePropertyList(elem1, elem2, elem3, elem4));
  }

  public nl.cwi.sen1.configapi.types.PropertyList makePropertyList(nl.cwi.sen1.configapi.types.Property elem0, nl.cwi.sen1.configapi.types.Property elem1, nl.cwi.sen1.configapi.types.Property elem2, nl.cwi.sen1.configapi.types.Property elem3, nl.cwi.sen1.configapi.types.Property elem4, nl.cwi.sen1.configapi.types.Property elem5) {
    return makePropertyList(elem0, makePropertyList(elem1, elem2, elem3, elem4, elem5));
  }

  public nl.cwi.sen1.configapi.types.PropertyList reverse(nl.cwi.sen1.configapi.types.PropertyList arg) {
    nl.cwi.sen1.configapi.types.PropertyList reversed = makePropertyList();
    while (!arg.isEmpty()) {
      reversed = makePropertyList(arg.getHead(), reversed);
      arg = arg.getTail();
    }
    return reversed;
  }

  public nl.cwi.sen1.configapi.types.PropertyList concat(nl.cwi.sen1.configapi.types.PropertyList arg0, nl.cwi.sen1.configapi.types.PropertyList arg1) {
    nl.cwi.sen1.configapi.types.PropertyList result = arg1;

    for (nl.cwi.sen1.configapi.types.PropertyList list = reverse(arg0); !list.isEmpty(); list = list.getTail()) {
      result = makePropertyList(list.getHead(), result);
    }

    return result;
  }

  public nl.cwi.sen1.configapi.types.PropertyList append(nl.cwi.sen1.configapi.types.PropertyList list, nl.cwi.sen1.configapi.types.Property elem) {
    return concat(list, makePropertyList(elem));
  }

  public nl.cwi.sen1.configapi.types.ActionDescriptionList makeActionDescriptionList() {
    return empty_ActionDescriptionList;
  }

  public nl.cwi.sen1.configapi.types.ActionDescriptionList makeActionDescriptionList(nl.cwi.sen1.configapi.types.ActionDescription elem) {
    return makeActionDescriptionList(elem, empty_ActionDescriptionList);
  }

  public nl.cwi.sen1.configapi.types.ActionDescriptionList makeActionDescriptionList(nl.cwi.sen1.configapi.types.ActionDescription head, nl.cwi.sen1.configapi.types.ActionDescriptionList tail) {
    return makeActionDescriptionList(head, tail, factory.getEmpty());
  }

  public nl.cwi.sen1.configapi.types.ActionDescriptionList makeActionDescriptionList(aterm.ATerm head, aterm.ATermList tail, aterm.ATermList annos) {
      return (nl.cwi.sen1.configapi.types.ActionDescriptionList) factory.build(new nl.cwi.sen1.configapi.types.ActionDescriptionList(this, annos, head, tail));
  }

  public nl.cwi.sen1.configapi.types.ActionDescriptionList makeActionDescriptionList(nl.cwi.sen1.configapi.types.ActionDescription elem0, nl.cwi.sen1.configapi.types.ActionDescription elem1) {
    return makeActionDescriptionList(elem0, makeActionDescriptionList(elem1));
  }

  public nl.cwi.sen1.configapi.types.ActionDescriptionList makeActionDescriptionList(nl.cwi.sen1.configapi.types.ActionDescription elem0, nl.cwi.sen1.configapi.types.ActionDescription elem1, nl.cwi.sen1.configapi.types.ActionDescription elem2) {
    return makeActionDescriptionList(elem0, makeActionDescriptionList(elem1, elem2));
  }

  public nl.cwi.sen1.configapi.types.ActionDescriptionList makeActionDescriptionList(nl.cwi.sen1.configapi.types.ActionDescription elem0, nl.cwi.sen1.configapi.types.ActionDescription elem1, nl.cwi.sen1.configapi.types.ActionDescription elem2, nl.cwi.sen1.configapi.types.ActionDescription elem3) {
    return makeActionDescriptionList(elem0, makeActionDescriptionList(elem1, elem2, elem3));
  }

  public nl.cwi.sen1.configapi.types.ActionDescriptionList makeActionDescriptionList(nl.cwi.sen1.configapi.types.ActionDescription elem0, nl.cwi.sen1.configapi.types.ActionDescription elem1, nl.cwi.sen1.configapi.types.ActionDescription elem2, nl.cwi.sen1.configapi.types.ActionDescription elem3, nl.cwi.sen1.configapi.types.ActionDescription elem4) {
    return makeActionDescriptionList(elem0, makeActionDescriptionList(elem1, elem2, elem3, elem4));
  }

  public nl.cwi.sen1.configapi.types.ActionDescriptionList makeActionDescriptionList(nl.cwi.sen1.configapi.types.ActionDescription elem0, nl.cwi.sen1.configapi.types.ActionDescription elem1, nl.cwi.sen1.configapi.types.ActionDescription elem2, nl.cwi.sen1.configapi.types.ActionDescription elem3, nl.cwi.sen1.configapi.types.ActionDescription elem4, nl.cwi.sen1.configapi.types.ActionDescription elem5) {
    return makeActionDescriptionList(elem0, makeActionDescriptionList(elem1, elem2, elem3, elem4, elem5));
  }

  public nl.cwi.sen1.configapi.types.ActionDescriptionList reverse(nl.cwi.sen1.configapi.types.ActionDescriptionList arg) {
    nl.cwi.sen1.configapi.types.ActionDescriptionList reversed = makeActionDescriptionList();
    while (!arg.isEmpty()) {
      reversed = makeActionDescriptionList(arg.getHead(), reversed);
      arg = arg.getTail();
    }
    return reversed;
  }

  public nl.cwi.sen1.configapi.types.ActionDescriptionList concat(nl.cwi.sen1.configapi.types.ActionDescriptionList arg0, nl.cwi.sen1.configapi.types.ActionDescriptionList arg1) {
    nl.cwi.sen1.configapi.types.ActionDescriptionList result = arg1;

    for (nl.cwi.sen1.configapi.types.ActionDescriptionList list = reverse(arg0); !list.isEmpty(); list = list.getTail()) {
      result = makeActionDescriptionList(list.getHead(), result);
    }

    return result;
  }

  public nl.cwi.sen1.configapi.types.ActionDescriptionList append(nl.cwi.sen1.configapi.types.ActionDescriptionList list, nl.cwi.sen1.configapi.types.ActionDescription elem) {
    return concat(list, makeActionDescriptionList(elem));
  }

  public nl.cwi.sen1.configapi.types.TextAttributeMap makeTextAttributeMap() {
    return empty_TextAttributeMap;
  }

  public nl.cwi.sen1.configapi.types.TextAttributeMap makeTextAttributeMap(nl.cwi.sen1.configapi.types.TextAttribute elem) {
    return makeTextAttributeMap(elem, empty_TextAttributeMap);
  }

  public nl.cwi.sen1.configapi.types.TextAttributeMap makeTextAttributeMap(nl.cwi.sen1.configapi.types.TextAttribute head, nl.cwi.sen1.configapi.types.TextAttributeMap tail) {
    return makeTextAttributeMap(head, tail, factory.getEmpty());
  }

  public nl.cwi.sen1.configapi.types.TextAttributeMap makeTextAttributeMap(aterm.ATerm head, aterm.ATermList tail, aterm.ATermList annos) {
      return (nl.cwi.sen1.configapi.types.TextAttributeMap) factory.build(new nl.cwi.sen1.configapi.types.TextAttributeMap(this, annos, head, tail));
  }

  public nl.cwi.sen1.configapi.types.TextAttributeMap makeTextAttributeMap(nl.cwi.sen1.configapi.types.TextAttribute elem0, nl.cwi.sen1.configapi.types.TextAttribute elem1) {
    return makeTextAttributeMap(elem0, makeTextAttributeMap(elem1));
  }

  public nl.cwi.sen1.configapi.types.TextAttributeMap makeTextAttributeMap(nl.cwi.sen1.configapi.types.TextAttribute elem0, nl.cwi.sen1.configapi.types.TextAttribute elem1, nl.cwi.sen1.configapi.types.TextAttribute elem2) {
    return makeTextAttributeMap(elem0, makeTextAttributeMap(elem1, elem2));
  }

  public nl.cwi.sen1.configapi.types.TextAttributeMap makeTextAttributeMap(nl.cwi.sen1.configapi.types.TextAttribute elem0, nl.cwi.sen1.configapi.types.TextAttribute elem1, nl.cwi.sen1.configapi.types.TextAttribute elem2, nl.cwi.sen1.configapi.types.TextAttribute elem3) {
    return makeTextAttributeMap(elem0, makeTextAttributeMap(elem1, elem2, elem3));
  }

  public nl.cwi.sen1.configapi.types.TextAttributeMap makeTextAttributeMap(nl.cwi.sen1.configapi.types.TextAttribute elem0, nl.cwi.sen1.configapi.types.TextAttribute elem1, nl.cwi.sen1.configapi.types.TextAttribute elem2, nl.cwi.sen1.configapi.types.TextAttribute elem3, nl.cwi.sen1.configapi.types.TextAttribute elem4) {
    return makeTextAttributeMap(elem0, makeTextAttributeMap(elem1, elem2, elem3, elem4));
  }

  public nl.cwi.sen1.configapi.types.TextAttributeMap makeTextAttributeMap(nl.cwi.sen1.configapi.types.TextAttribute elem0, nl.cwi.sen1.configapi.types.TextAttribute elem1, nl.cwi.sen1.configapi.types.TextAttribute elem2, nl.cwi.sen1.configapi.types.TextAttribute elem3, nl.cwi.sen1.configapi.types.TextAttribute elem4, nl.cwi.sen1.configapi.types.TextAttribute elem5) {
    return makeTextAttributeMap(elem0, makeTextAttributeMap(elem1, elem2, elem3, elem4, elem5));
  }

  public nl.cwi.sen1.configapi.types.TextAttributeMap reverse(nl.cwi.sen1.configapi.types.TextAttributeMap arg) {
    nl.cwi.sen1.configapi.types.TextAttributeMap reversed = makeTextAttributeMap();
    while (!arg.isEmpty()) {
      reversed = makeTextAttributeMap(arg.getHead(), reversed);
      arg = arg.getTail();
    }
    return reversed;
  }

  public nl.cwi.sen1.configapi.types.TextAttributeMap concat(nl.cwi.sen1.configapi.types.TextAttributeMap arg0, nl.cwi.sen1.configapi.types.TextAttributeMap arg1) {
    nl.cwi.sen1.configapi.types.TextAttributeMap result = arg1;

    for (nl.cwi.sen1.configapi.types.TextAttributeMap list = reverse(arg0); !list.isEmpty(); list = list.getTail()) {
      result = makeTextAttributeMap(list.getHead(), result);
    }

    return result;
  }

  public nl.cwi.sen1.configapi.types.TextAttributeMap append(nl.cwi.sen1.configapi.types.TextAttributeMap list, nl.cwi.sen1.configapi.types.TextAttribute elem) {
    return concat(list, makeTextAttributeMap(elem));
  }

  public nl.cwi.sen1.configapi.types.KeyModifierList makeKeyModifierList() {
    return empty_KeyModifierList;
  }

  public nl.cwi.sen1.configapi.types.KeyModifierList makeKeyModifierList(nl.cwi.sen1.configapi.types.KeyModifier elem) {
    return makeKeyModifierList(elem, empty_KeyModifierList);
  }

  public nl.cwi.sen1.configapi.types.KeyModifierList makeKeyModifierList(nl.cwi.sen1.configapi.types.KeyModifier head, nl.cwi.sen1.configapi.types.KeyModifierList tail) {
    return makeKeyModifierList(head, tail, factory.getEmpty());
  }

  public nl.cwi.sen1.configapi.types.KeyModifierList makeKeyModifierList(aterm.ATerm head, aterm.ATermList tail, aterm.ATermList annos) {
      return (nl.cwi.sen1.configapi.types.KeyModifierList) factory.build(new nl.cwi.sen1.configapi.types.KeyModifierList(this, annos, head, tail));
  }

  public nl.cwi.sen1.configapi.types.KeyModifierList makeKeyModifierList(nl.cwi.sen1.configapi.types.KeyModifier elem0, nl.cwi.sen1.configapi.types.KeyModifier elem1) {
    return makeKeyModifierList(elem0, makeKeyModifierList(elem1));
  }

  public nl.cwi.sen1.configapi.types.KeyModifierList makeKeyModifierList(nl.cwi.sen1.configapi.types.KeyModifier elem0, nl.cwi.sen1.configapi.types.KeyModifier elem1, nl.cwi.sen1.configapi.types.KeyModifier elem2) {
    return makeKeyModifierList(elem0, makeKeyModifierList(elem1, elem2));
  }

  public nl.cwi.sen1.configapi.types.KeyModifierList makeKeyModifierList(nl.cwi.sen1.configapi.types.KeyModifier elem0, nl.cwi.sen1.configapi.types.KeyModifier elem1, nl.cwi.sen1.configapi.types.KeyModifier elem2, nl.cwi.sen1.configapi.types.KeyModifier elem3) {
    return makeKeyModifierList(elem0, makeKeyModifierList(elem1, elem2, elem3));
  }

  public nl.cwi.sen1.configapi.types.KeyModifierList makeKeyModifierList(nl.cwi.sen1.configapi.types.KeyModifier elem0, nl.cwi.sen1.configapi.types.KeyModifier elem1, nl.cwi.sen1.configapi.types.KeyModifier elem2, nl.cwi.sen1.configapi.types.KeyModifier elem3, nl.cwi.sen1.configapi.types.KeyModifier elem4) {
    return makeKeyModifierList(elem0, makeKeyModifierList(elem1, elem2, elem3, elem4));
  }

  public nl.cwi.sen1.configapi.types.KeyModifierList makeKeyModifierList(nl.cwi.sen1.configapi.types.KeyModifier elem0, nl.cwi.sen1.configapi.types.KeyModifier elem1, nl.cwi.sen1.configapi.types.KeyModifier elem2, nl.cwi.sen1.configapi.types.KeyModifier elem3, nl.cwi.sen1.configapi.types.KeyModifier elem4, nl.cwi.sen1.configapi.types.KeyModifier elem5) {
    return makeKeyModifierList(elem0, makeKeyModifierList(elem1, elem2, elem3, elem4, elem5));
  }

  public nl.cwi.sen1.configapi.types.KeyModifierList reverse(nl.cwi.sen1.configapi.types.KeyModifierList arg) {
    nl.cwi.sen1.configapi.types.KeyModifierList reversed = makeKeyModifierList();
    while (!arg.isEmpty()) {
      reversed = makeKeyModifierList(arg.getHead(), reversed);
      arg = arg.getTail();
    }
    return reversed;
  }

  public nl.cwi.sen1.configapi.types.KeyModifierList concat(nl.cwi.sen1.configapi.types.KeyModifierList arg0, nl.cwi.sen1.configapi.types.KeyModifierList arg1) {
    nl.cwi.sen1.configapi.types.KeyModifierList result = arg1;

    for (nl.cwi.sen1.configapi.types.KeyModifierList list = reverse(arg0); !list.isEmpty(); list = list.getTail()) {
      result = makeKeyModifierList(list.getHead(), result);
    }

    return result;
  }

  public nl.cwi.sen1.configapi.types.KeyModifierList append(nl.cwi.sen1.configapi.types.KeyModifierList list, nl.cwi.sen1.configapi.types.KeyModifier elem) {
    return concat(list, makeKeyModifierList(elem));
  }

  public nl.cwi.sen1.configapi.types.ItemLabels makeItemLabels() {
    return empty_ItemLabels;
  }

  public nl.cwi.sen1.configapi.types.ItemLabels makeItemLabels(nl.cwi.sen1.configapi.types.Item elem) {
    return makeItemLabels(elem, empty_ItemLabels);
  }

  public nl.cwi.sen1.configapi.types.ItemLabels makeItemLabels(nl.cwi.sen1.configapi.types.Item head, nl.cwi.sen1.configapi.types.ItemLabels tail) {
    return makeItemLabels(head, tail, factory.getEmpty());
  }

  public nl.cwi.sen1.configapi.types.ItemLabels makeItemLabels(aterm.ATerm head, aterm.ATermList tail, aterm.ATermList annos) {
      return (nl.cwi.sen1.configapi.types.ItemLabels) factory.build(new nl.cwi.sen1.configapi.types.ItemLabels(this, annos, head, tail));
  }

  public nl.cwi.sen1.configapi.types.ItemLabels makeItemLabels(nl.cwi.sen1.configapi.types.Item elem0, nl.cwi.sen1.configapi.types.Item elem1) {
    return makeItemLabels(elem0, makeItemLabels(elem1));
  }

  public nl.cwi.sen1.configapi.types.ItemLabels makeItemLabels(nl.cwi.sen1.configapi.types.Item elem0, nl.cwi.sen1.configapi.types.Item elem1, nl.cwi.sen1.configapi.types.Item elem2) {
    return makeItemLabels(elem0, makeItemLabels(elem1, elem2));
  }

  public nl.cwi.sen1.configapi.types.ItemLabels makeItemLabels(nl.cwi.sen1.configapi.types.Item elem0, nl.cwi.sen1.configapi.types.Item elem1, nl.cwi.sen1.configapi.types.Item elem2, nl.cwi.sen1.configapi.types.Item elem3) {
    return makeItemLabels(elem0, makeItemLabels(elem1, elem2, elem3));
  }

  public nl.cwi.sen1.configapi.types.ItemLabels makeItemLabels(nl.cwi.sen1.configapi.types.Item elem0, nl.cwi.sen1.configapi.types.Item elem1, nl.cwi.sen1.configapi.types.Item elem2, nl.cwi.sen1.configapi.types.Item elem3, nl.cwi.sen1.configapi.types.Item elem4) {
    return makeItemLabels(elem0, makeItemLabels(elem1, elem2, elem3, elem4));
  }

  public nl.cwi.sen1.configapi.types.ItemLabels makeItemLabels(nl.cwi.sen1.configapi.types.Item elem0, nl.cwi.sen1.configapi.types.Item elem1, nl.cwi.sen1.configapi.types.Item elem2, nl.cwi.sen1.configapi.types.Item elem3, nl.cwi.sen1.configapi.types.Item elem4, nl.cwi.sen1.configapi.types.Item elem5) {
    return makeItemLabels(elem0, makeItemLabels(elem1, elem2, elem3, elem4, elem5));
  }

  public nl.cwi.sen1.configapi.types.ItemLabels reverse(nl.cwi.sen1.configapi.types.ItemLabels arg) {
    nl.cwi.sen1.configapi.types.ItemLabels reversed = makeItemLabels();
    while (!arg.isEmpty()) {
      reversed = makeItemLabels(arg.getHead(), reversed);
      arg = arg.getTail();
    }
    return reversed;
  }

  public nl.cwi.sen1.configapi.types.ItemLabels concat(nl.cwi.sen1.configapi.types.ItemLabels arg0, nl.cwi.sen1.configapi.types.ItemLabels arg1) {
    nl.cwi.sen1.configapi.types.ItemLabels result = arg1;

    for (nl.cwi.sen1.configapi.types.ItemLabels list = reverse(arg0); !list.isEmpty(); list = list.getTail()) {
      result = makeItemLabels(list.getHead(), result);
    }

    return result;
  }

  public nl.cwi.sen1.configapi.types.ItemLabels append(nl.cwi.sen1.configapi.types.ItemLabels list, nl.cwi.sen1.configapi.types.Item elem) {
    return concat(list, makeItemLabels(elem));
  }

/*genTypeFromTermMethods*/
  public nl.cwi.sen1.configapi.types.VirtualButton VirtualButtonFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.configapi.types.VirtualButton tmp;
    tmp = VirtualButton_NOBUTTONFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualButton_BUTTON1FromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualButton_BUTTON2FromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualButton_BUTTON3FromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a VirtualButton: " + trm);
  }

  public nl.cwi.sen1.configapi.types.KeyModifier KeyModifierFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.configapi.types.KeyModifier tmp;
    tmp = KeyModifier_MUnderscoreALTFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = KeyModifier_MUnderscoreCTRLFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = KeyModifier_MUnderscoreSHIFTFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a KeyModifier: " + trm);
  }

  public nl.cwi.sen1.configapi.types.VirtualKey VirtualKeyFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.configapi.types.VirtualKey tmp;
    tmp = VirtualKey_VKUnderscore0FromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscore1FromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscore2FromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscore3FromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscore4FromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscore5FromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscore6FromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscore7FromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscore8FromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscore9FromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreAFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreBFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreCFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreDFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreEFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreFFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreGFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreHFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreIFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreJFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreKFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreLFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreMFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreNFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreOFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscorePFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreQFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreRFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreSFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreTFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreUFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreVFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreWFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreXFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreYFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreZFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreAMPERSANDFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreASTERISKFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreATFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreBACKUnderscoreQUOTEFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreBACKUnderscoreSLASHFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreBACKUnderscoreSPACEFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreBEGINFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreBRACEUnderscoreLEFTFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreBRACEUnderscoreRIGHTFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreCIRCUMFLEXFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreCLEARFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreCLOSEUnderscoreBRACKETFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreCOLONFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreCOMMAFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreDECIMALFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreDELETEFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreDIVIDEFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreDOLLARFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreDOWNFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreENDFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreENTERFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreEQUALSFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreESCAPEFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreEXCLAMATIONUnderscoreMARKFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreF1FromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreF2FromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreF3FromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreF4FromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreF5FromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreF6FromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreF7FromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreF8FromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreF9FromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreF10FromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreF11FromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreF12FromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreGREATERFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreHOMEFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreINSERTFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreLEFTFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreLEFTUnderscorePARENTHESISFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreMINUSFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreMULTIPLYFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreNUMBERUnderscoreSIGNFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreOPENUnderscoreBRACKETFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscorePAGEUnderscoreDOWNFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscorePAGEUnderscoreUPFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscorePAUSEFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscorePERIODFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscorePLUSFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscorePRINTSCREENFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreQUOTEFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreQUOTEDBLFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreRIGHTFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreRIGHTUnderscorePARENTHESISFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreSEMICOLONFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreSLASHFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreSPACEFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreSUBTRACTFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreTABFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreUNDERSCOREFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VKUnderscoreUPFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a VirtualKey: " + trm);
  }

  public nl.cwi.sen1.configapi.types.Color ColorFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.configapi.types.Color tmp;
    tmp = Color_RgbFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a Color: " + trm);
  }

  public nl.cwi.sen1.configapi.types.Configuration ConfigurationFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.configapi.types.Configuration tmp;
    tmp = Configuration_ConfigurationFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a Configuration: " + trm);
  }

  public nl.cwi.sen1.configapi.types.Property PropertyFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.configapi.types.Property tmp;
    tmp = Property_ImportFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Property_ScriptFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Property_ScriptPathFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Property_ActionFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Property_EditorFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Property_LibraryPathFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Property_ModulePathFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Property_TextCategoryFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a Property: " + trm);
  }

  public nl.cwi.sen1.configapi.types.ActionDescription ActionDescriptionFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.configapi.types.ActionDescription tmp;
    tmp = ActionDescription_DescriptionFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a ActionDescription: " + trm);
  }

  public nl.cwi.sen1.configapi.types.Event EventFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.configapi.types.Event tmp;
    tmp = Event_PopupFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Event_ClickFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Event_IconFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Event_MenuFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = Event_MenuShortcutFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a Event: " + trm);
  }

  public nl.cwi.sen1.configapi.types.Item ItemFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.configapi.types.Item tmp;
    tmp = Item_LabelFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a Item: " + trm);
  }

  public nl.cwi.sen1.configapi.types.TextCategoryName TextCategoryNameFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.configapi.types.TextCategoryName tmp;
    tmp = TextCategoryName_FocusFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = TextCategoryName_SelectionFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = TextCategoryName_NormalFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = TextCategoryName_ExternFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a TextCategoryName: " + trm);
  }

  public nl.cwi.sen1.configapi.types.TextAttribute TextAttributeFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.configapi.types.TextAttribute tmp;
    tmp = TextAttribute_ForegroundColorFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = TextAttribute_BackgroundColorFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = TextAttribute_StyleFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = TextAttribute_FontFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = TextAttribute_SizeFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a TextAttribute: " + trm);
  }

  public nl.cwi.sen1.configapi.types.ShortCut ShortCutFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.configapi.types.ShortCut tmp;
    tmp = ShortCut_ShortcutFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a ShortCut: " + trm);
  }

  public nl.cwi.sen1.configapi.types.TextStyle TextStyleFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.configapi.types.TextStyle tmp;
    tmp = TextStyle_BoldFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = TextStyle_ItalicsFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = TextStyle_UnderlinedFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a TextStyle: " + trm);
  }

  public nl.cwi.sen1.configapi.types.PropertyList PropertyListFromTerm(aterm.ATerm trm) {
     if (trm instanceof aterm.ATermList) {
        aterm.ATermList list = ((aterm.ATermList) trm).reverse();
        nl.cwi.sen1.configapi.types.PropertyList result = makePropertyList();
        for (; !list.isEmpty(); list = list.getNext()) {
           nl.cwi.sen1.configapi.types.Property elem = PropertyFromTerm(list.getFirst());
            result = makePropertyList(elem, result);
        }
        return result;
     }
     throw new RuntimeException("This is not a PropertyList: " + trm);
  }

  public nl.cwi.sen1.configapi.types.ActionDescriptionList ActionDescriptionListFromTerm(aterm.ATerm trm) {
     if (trm instanceof aterm.ATermList) {
        aterm.ATermList list = ((aterm.ATermList) trm).reverse();
        nl.cwi.sen1.configapi.types.ActionDescriptionList result = makeActionDescriptionList();
        for (; !list.isEmpty(); list = list.getNext()) {
           nl.cwi.sen1.configapi.types.ActionDescription elem = ActionDescriptionFromTerm(list.getFirst());
            result = makeActionDescriptionList(elem, result);
        }
        return result;
     }
     throw new RuntimeException("This is not a ActionDescriptionList: " + trm);
  }

  public nl.cwi.sen1.configapi.types.TextAttributeMap TextAttributeMapFromTerm(aterm.ATerm trm) {
     if (trm instanceof aterm.ATermList) {
        aterm.ATermList list = ((aterm.ATermList) trm).reverse();
        nl.cwi.sen1.configapi.types.TextAttributeMap result = makeTextAttributeMap();
        for (; !list.isEmpty(); list = list.getNext()) {
           nl.cwi.sen1.configapi.types.TextAttribute elem = TextAttributeFromTerm(list.getFirst());
            result = makeTextAttributeMap(elem, result);
        }
        return result;
     }
     throw new RuntimeException("This is not a TextAttributeMap: " + trm);
  }

  public nl.cwi.sen1.configapi.types.KeyModifierList KeyModifierListFromTerm(aterm.ATerm trm) {
     if (trm instanceof aterm.ATermList) {
        aterm.ATermList list = ((aterm.ATermList) trm).reverse();
        nl.cwi.sen1.configapi.types.KeyModifierList result = makeKeyModifierList();
        for (; !list.isEmpty(); list = list.getNext()) {
           nl.cwi.sen1.configapi.types.KeyModifier elem = KeyModifierFromTerm(list.getFirst());
            result = makeKeyModifierList(elem, result);
        }
        return result;
     }
     throw new RuntimeException("This is not a KeyModifierList: " + trm);
  }

  public nl.cwi.sen1.configapi.types.ItemLabels ItemLabelsFromTerm(aterm.ATerm trm) {
     if (trm instanceof aterm.ATermList) {
        aterm.ATermList list = ((aterm.ATermList) trm).reverse();
        nl.cwi.sen1.configapi.types.ItemLabels result = makeItemLabels();
        for (; !list.isEmpty(); list = list.getNext()) {
           nl.cwi.sen1.configapi.types.Item elem = ItemFromTerm(list.getFirst());
            result = makeItemLabels(elem, result);
        }
        return result;
     }
     throw new RuntimeException("This is not a ItemLabels: " + trm);
  }

/*genTypeFromMethods*/
  public nl.cwi.sen1.configapi.types.VirtualButton VirtualButtonFromString(String str) {
    return VirtualButtonFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.configapi.types.VirtualButton VirtualButtonFromFile(java.io.InputStream stream) throws java.io.IOException {
    return VirtualButtonFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.configapi.types.KeyModifier KeyModifierFromString(String str) {
    return KeyModifierFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.configapi.types.KeyModifier KeyModifierFromFile(java.io.InputStream stream) throws java.io.IOException {
    return KeyModifierFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.configapi.types.VirtualKey VirtualKeyFromString(String str) {
    return VirtualKeyFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.configapi.types.VirtualKey VirtualKeyFromFile(java.io.InputStream stream) throws java.io.IOException {
    return VirtualKeyFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.configapi.types.Color ColorFromString(String str) {
    return ColorFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.configapi.types.Color ColorFromFile(java.io.InputStream stream) throws java.io.IOException {
    return ColorFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.configapi.types.Configuration ConfigurationFromString(String str) {
    return ConfigurationFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.configapi.types.Configuration ConfigurationFromFile(java.io.InputStream stream) throws java.io.IOException {
    return ConfigurationFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.configapi.types.Property PropertyFromString(String str) {
    return PropertyFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.configapi.types.Property PropertyFromFile(java.io.InputStream stream) throws java.io.IOException {
    return PropertyFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.configapi.types.ActionDescription ActionDescriptionFromString(String str) {
    return ActionDescriptionFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.configapi.types.ActionDescription ActionDescriptionFromFile(java.io.InputStream stream) throws java.io.IOException {
    return ActionDescriptionFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.configapi.types.Event EventFromString(String str) {
    return EventFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.configapi.types.Event EventFromFile(java.io.InputStream stream) throws java.io.IOException {
    return EventFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.configapi.types.Item ItemFromString(String str) {
    return ItemFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.configapi.types.Item ItemFromFile(java.io.InputStream stream) throws java.io.IOException {
    return ItemFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.configapi.types.TextCategoryName TextCategoryNameFromString(String str) {
    return TextCategoryNameFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.configapi.types.TextCategoryName TextCategoryNameFromFile(java.io.InputStream stream) throws java.io.IOException {
    return TextCategoryNameFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.configapi.types.TextAttribute TextAttributeFromString(String str) {
    return TextAttributeFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.configapi.types.TextAttribute TextAttributeFromFile(java.io.InputStream stream) throws java.io.IOException {
    return TextAttributeFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.configapi.types.ShortCut ShortCutFromString(String str) {
    return ShortCutFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.configapi.types.ShortCut ShortCutFromFile(java.io.InputStream stream) throws java.io.IOException {
    return ShortCutFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.configapi.types.TextStyle TextStyleFromString(String str) {
    return TextStyleFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.configapi.types.TextStyle TextStyleFromFile(java.io.InputStream stream) throws java.io.IOException {
    return TextStyleFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.configapi.types.PropertyList PropertyListFromString(String str) {
    return PropertyListFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.configapi.types.PropertyList PropertyListFromFile(java.io.InputStream stream) throws java.io.IOException {
    return PropertyListFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.configapi.types.ActionDescriptionList ActionDescriptionListFromString(String str) {
    return ActionDescriptionListFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.configapi.types.ActionDescriptionList ActionDescriptionListFromFile(java.io.InputStream stream) throws java.io.IOException {
    return ActionDescriptionListFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.configapi.types.TextAttributeMap TextAttributeMapFromString(String str) {
    return TextAttributeMapFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.configapi.types.TextAttributeMap TextAttributeMapFromFile(java.io.InputStream stream) throws java.io.IOException {
    return TextAttributeMapFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.configapi.types.KeyModifierList KeyModifierListFromString(String str) {
    return KeyModifierListFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.configapi.types.KeyModifierList KeyModifierListFromFile(java.io.InputStream stream) throws java.io.IOException {
    return KeyModifierListFromTerm(factory.readFromFile(stream));
  }

  public nl.cwi.sen1.configapi.types.ItemLabels ItemLabelsFromString(String str) {
    return ItemLabelsFromTerm(factory.parse(str));
  }

  public nl.cwi.sen1.configapi.types.ItemLabels ItemLabelsFromFile(java.io.InputStream stream) throws java.io.IOException {
    return ItemLabelsFromTerm(factory.readFromFile(stream));
  }

/*genForwardingAlternativeMethods*/
/*genForwardingMakeLists*/
/*genForwardingTypeFromTermMethods*/
/*TODOgenForwardingTypeFromMethods*/
  public static String charsToString(aterm.ATerm arg) {
    aterm.ATermList list = (aterm.ATermList) arg;
    StringBuffer str = new StringBuffer();

    for ( ; !list.isEmpty(); list = list.getNext()) {
      str.append((char) ((aterm.ATermInt) list.getFirst()).getInt());
    }

    return str.toString();
  }

  public static char charToByte(aterm.ATerm arg) {

      return((char) ((aterm.ATermInt) arg).getInt());
  }

  public aterm.ATerm stringToChars(String str) {
    int len = str.length();
    byte chars[] = str.getBytes();
    aterm.ATermList result = getPureFactory().makeList();

    for (int i = len - 1; i >= 0; i--) {
      result = result.insert(getPureFactory().makeInt(chars[i]));
    }

    return result;
  }

  public aterm.ATerm byteToChar(char ch) {
      return getPureFactory().makeInt(ch);
  }

}
