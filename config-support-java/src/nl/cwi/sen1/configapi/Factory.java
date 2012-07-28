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

  private aterm.AFun fun_KeyModifier_M_ALT;
  private aterm.ATerm pattern_KeyModifier_M_ALT;
  private aterm.AFun fun_KeyModifier_M_CTRL;
  private aterm.ATerm pattern_KeyModifier_M_CTRL;
  private aterm.AFun fun_KeyModifier_M_SHIFT;
  private aterm.ATerm pattern_KeyModifier_M_SHIFT;

  private aterm.AFun fun_VirtualKey_VK_0;
  private aterm.ATerm pattern_VirtualKey_VK_0;
  private aterm.AFun fun_VirtualKey_VK_1;
  private aterm.ATerm pattern_VirtualKey_VK_1;
  private aterm.AFun fun_VirtualKey_VK_2;
  private aterm.ATerm pattern_VirtualKey_VK_2;
  private aterm.AFun fun_VirtualKey_VK_3;
  private aterm.ATerm pattern_VirtualKey_VK_3;
  private aterm.AFun fun_VirtualKey_VK_4;
  private aterm.ATerm pattern_VirtualKey_VK_4;
  private aterm.AFun fun_VirtualKey_VK_5;
  private aterm.ATerm pattern_VirtualKey_VK_5;
  private aterm.AFun fun_VirtualKey_VK_6;
  private aterm.ATerm pattern_VirtualKey_VK_6;
  private aterm.AFun fun_VirtualKey_VK_7;
  private aterm.ATerm pattern_VirtualKey_VK_7;
  private aterm.AFun fun_VirtualKey_VK_8;
  private aterm.ATerm pattern_VirtualKey_VK_8;
  private aterm.AFun fun_VirtualKey_VK_9;
  private aterm.ATerm pattern_VirtualKey_VK_9;
  private aterm.AFun fun_VirtualKey_VK_A;
  private aterm.ATerm pattern_VirtualKey_VK_A;
  private aterm.AFun fun_VirtualKey_VK_B;
  private aterm.ATerm pattern_VirtualKey_VK_B;
  private aterm.AFun fun_VirtualKey_VK_C;
  private aterm.ATerm pattern_VirtualKey_VK_C;
  private aterm.AFun fun_VirtualKey_VK_D;
  private aterm.ATerm pattern_VirtualKey_VK_D;
  private aterm.AFun fun_VirtualKey_VK_E;
  private aterm.ATerm pattern_VirtualKey_VK_E;
  private aterm.AFun fun_VirtualKey_VK_F;
  private aterm.ATerm pattern_VirtualKey_VK_F;
  private aterm.AFun fun_VirtualKey_VK_G;
  private aterm.ATerm pattern_VirtualKey_VK_G;
  private aterm.AFun fun_VirtualKey_VK_H;
  private aterm.ATerm pattern_VirtualKey_VK_H;
  private aterm.AFun fun_VirtualKey_VK_I;
  private aterm.ATerm pattern_VirtualKey_VK_I;
  private aterm.AFun fun_VirtualKey_VK_J;
  private aterm.ATerm pattern_VirtualKey_VK_J;
  private aterm.AFun fun_VirtualKey_VK_K;
  private aterm.ATerm pattern_VirtualKey_VK_K;
  private aterm.AFun fun_VirtualKey_VK_L;
  private aterm.ATerm pattern_VirtualKey_VK_L;
  private aterm.AFun fun_VirtualKey_VK_M;
  private aterm.ATerm pattern_VirtualKey_VK_M;
  private aterm.AFun fun_VirtualKey_VK_N;
  private aterm.ATerm pattern_VirtualKey_VK_N;
  private aterm.AFun fun_VirtualKey_VK_O;
  private aterm.ATerm pattern_VirtualKey_VK_O;
  private aterm.AFun fun_VirtualKey_VK_P;
  private aterm.ATerm pattern_VirtualKey_VK_P;
  private aterm.AFun fun_VirtualKey_VK_Q;
  private aterm.ATerm pattern_VirtualKey_VK_Q;
  private aterm.AFun fun_VirtualKey_VK_R;
  private aterm.ATerm pattern_VirtualKey_VK_R;
  private aterm.AFun fun_VirtualKey_VK_S;
  private aterm.ATerm pattern_VirtualKey_VK_S;
  private aterm.AFun fun_VirtualKey_VK_T;
  private aterm.ATerm pattern_VirtualKey_VK_T;
  private aterm.AFun fun_VirtualKey_VK_U;
  private aterm.ATerm pattern_VirtualKey_VK_U;
  private aterm.AFun fun_VirtualKey_VK_V;
  private aterm.ATerm pattern_VirtualKey_VK_V;
  private aterm.AFun fun_VirtualKey_VK_W;
  private aterm.ATerm pattern_VirtualKey_VK_W;
  private aterm.AFun fun_VirtualKey_VK_X;
  private aterm.ATerm pattern_VirtualKey_VK_X;
  private aterm.AFun fun_VirtualKey_VK_Y;
  private aterm.ATerm pattern_VirtualKey_VK_Y;
  private aterm.AFun fun_VirtualKey_VK_Z;
  private aterm.ATerm pattern_VirtualKey_VK_Z;
  private aterm.AFun fun_VirtualKey_VK_AMPERSAND;
  private aterm.ATerm pattern_VirtualKey_VK_AMPERSAND;
  private aterm.AFun fun_VirtualKey_VK_ASTERISK;
  private aterm.ATerm pattern_VirtualKey_VK_ASTERISK;
  private aterm.AFun fun_VirtualKey_VK_AT;
  private aterm.ATerm pattern_VirtualKey_VK_AT;
  private aterm.AFun fun_VirtualKey_VK_BACK_QUOTE;
  private aterm.ATerm pattern_VirtualKey_VK_BACK_QUOTE;
  private aterm.AFun fun_VirtualKey_VK_BACK_SLASH;
  private aterm.ATerm pattern_VirtualKey_VK_BACK_SLASH;
  private aterm.AFun fun_VirtualKey_VK_BACK_SPACE;
  private aterm.ATerm pattern_VirtualKey_VK_BACK_SPACE;
  private aterm.AFun fun_VirtualKey_VK_BEGIN;
  private aterm.ATerm pattern_VirtualKey_VK_BEGIN;
  private aterm.AFun fun_VirtualKey_VK_BRACE_LEFT;
  private aterm.ATerm pattern_VirtualKey_VK_BRACE_LEFT;
  private aterm.AFun fun_VirtualKey_VK_BRACE_RIGHT;
  private aterm.ATerm pattern_VirtualKey_VK_BRACE_RIGHT;
  private aterm.AFun fun_VirtualKey_VK_CIRCUMFLEX;
  private aterm.ATerm pattern_VirtualKey_VK_CIRCUMFLEX;
  private aterm.AFun fun_VirtualKey_VK_CLEAR;
  private aterm.ATerm pattern_VirtualKey_VK_CLEAR;
  private aterm.AFun fun_VirtualKey_VK_CLOSE_BRACKET;
  private aterm.ATerm pattern_VirtualKey_VK_CLOSE_BRACKET;
  private aterm.AFun fun_VirtualKey_VK_COLON;
  private aterm.ATerm pattern_VirtualKey_VK_COLON;
  private aterm.AFun fun_VirtualKey_VK_COMMA;
  private aterm.ATerm pattern_VirtualKey_VK_COMMA;
  private aterm.AFun fun_VirtualKey_VK_DECIMAL;
  private aterm.ATerm pattern_VirtualKey_VK_DECIMAL;
  private aterm.AFun fun_VirtualKey_VK_DELETE;
  private aterm.ATerm pattern_VirtualKey_VK_DELETE;
  private aterm.AFun fun_VirtualKey_VK_DIVIDE;
  private aterm.ATerm pattern_VirtualKey_VK_DIVIDE;
  private aterm.AFun fun_VirtualKey_VK_DOLLAR;
  private aterm.ATerm pattern_VirtualKey_VK_DOLLAR;
  private aterm.AFun fun_VirtualKey_VK_DOWN;
  private aterm.ATerm pattern_VirtualKey_VK_DOWN;
  private aterm.AFun fun_VirtualKey_VK_END;
  private aterm.ATerm pattern_VirtualKey_VK_END;
  private aterm.AFun fun_VirtualKey_VK_ENTER;
  private aterm.ATerm pattern_VirtualKey_VK_ENTER;
  private aterm.AFun fun_VirtualKey_VK_EQUALS;
  private aterm.ATerm pattern_VirtualKey_VK_EQUALS;
  private aterm.AFun fun_VirtualKey_VK_ESCAPE;
  private aterm.ATerm pattern_VirtualKey_VK_ESCAPE;
  private aterm.AFun fun_VirtualKey_VK_EXCLAMATION_MARK;
  private aterm.ATerm pattern_VirtualKey_VK_EXCLAMATION_MARK;
  private aterm.AFun fun_VirtualKey_VK_F1;
  private aterm.ATerm pattern_VirtualKey_VK_F1;
  private aterm.AFun fun_VirtualKey_VK_F2;
  private aterm.ATerm pattern_VirtualKey_VK_F2;
  private aterm.AFun fun_VirtualKey_VK_F3;
  private aterm.ATerm pattern_VirtualKey_VK_F3;
  private aterm.AFun fun_VirtualKey_VK_F4;
  private aterm.ATerm pattern_VirtualKey_VK_F4;
  private aterm.AFun fun_VirtualKey_VK_F5;
  private aterm.ATerm pattern_VirtualKey_VK_F5;
  private aterm.AFun fun_VirtualKey_VK_F6;
  private aterm.ATerm pattern_VirtualKey_VK_F6;
  private aterm.AFun fun_VirtualKey_VK_F7;
  private aterm.ATerm pattern_VirtualKey_VK_F7;
  private aterm.AFun fun_VirtualKey_VK_F8;
  private aterm.ATerm pattern_VirtualKey_VK_F8;
  private aterm.AFun fun_VirtualKey_VK_F9;
  private aterm.ATerm pattern_VirtualKey_VK_F9;
  private aterm.AFun fun_VirtualKey_VK_F10;
  private aterm.ATerm pattern_VirtualKey_VK_F10;
  private aterm.AFun fun_VirtualKey_VK_F11;
  private aterm.ATerm pattern_VirtualKey_VK_F11;
  private aterm.AFun fun_VirtualKey_VK_F12;
  private aterm.ATerm pattern_VirtualKey_VK_F12;
  private aterm.AFun fun_VirtualKey_VK_GREATER;
  private aterm.ATerm pattern_VirtualKey_VK_GREATER;
  private aterm.AFun fun_VirtualKey_VK_HOME;
  private aterm.ATerm pattern_VirtualKey_VK_HOME;
  private aterm.AFun fun_VirtualKey_VK_INSERT;
  private aterm.ATerm pattern_VirtualKey_VK_INSERT;
  private aterm.AFun fun_VirtualKey_VK_LEFT;
  private aterm.ATerm pattern_VirtualKey_VK_LEFT;
  private aterm.AFun fun_VirtualKey_VK_LEFT_PARENTHESIS;
  private aterm.ATerm pattern_VirtualKey_VK_LEFT_PARENTHESIS;
  private aterm.AFun fun_VirtualKey_VK_MINUS;
  private aterm.ATerm pattern_VirtualKey_VK_MINUS;
  private aterm.AFun fun_VirtualKey_VK_MULTIPLY;
  private aterm.ATerm pattern_VirtualKey_VK_MULTIPLY;
  private aterm.AFun fun_VirtualKey_VK_NUMBER_SIGN;
  private aterm.ATerm pattern_VirtualKey_VK_NUMBER_SIGN;
  private aterm.AFun fun_VirtualKey_VK_OPEN_BRACKET;
  private aterm.ATerm pattern_VirtualKey_VK_OPEN_BRACKET;
  private aterm.AFun fun_VirtualKey_VK_PAGE_DOWN;
  private aterm.ATerm pattern_VirtualKey_VK_PAGE_DOWN;
  private aterm.AFun fun_VirtualKey_VK_PAGE_UP;
  private aterm.ATerm pattern_VirtualKey_VK_PAGE_UP;
  private aterm.AFun fun_VirtualKey_VK_PAUSE;
  private aterm.ATerm pattern_VirtualKey_VK_PAUSE;
  private aterm.AFun fun_VirtualKey_VK_PERIOD;
  private aterm.ATerm pattern_VirtualKey_VK_PERIOD;
  private aterm.AFun fun_VirtualKey_VK_PLUS;
  private aterm.ATerm pattern_VirtualKey_VK_PLUS;
  private aterm.AFun fun_VirtualKey_VK_PRINTSCREEN;
  private aterm.ATerm pattern_VirtualKey_VK_PRINTSCREEN;
  private aterm.AFun fun_VirtualKey_VK_QUOTE;
  private aterm.ATerm pattern_VirtualKey_VK_QUOTE;
  private aterm.AFun fun_VirtualKey_VK_QUOTEDBL;
  private aterm.ATerm pattern_VirtualKey_VK_QUOTEDBL;
  private aterm.AFun fun_VirtualKey_VK_RIGHT;
  private aterm.ATerm pattern_VirtualKey_VK_RIGHT;
  private aterm.AFun fun_VirtualKey_VK_RIGHT_PARENTHESIS;
  private aterm.ATerm pattern_VirtualKey_VK_RIGHT_PARENTHESIS;
  private aterm.AFun fun_VirtualKey_VK_SEMICOLON;
  private aterm.ATerm pattern_VirtualKey_VK_SEMICOLON;
  private aterm.AFun fun_VirtualKey_VK_SLASH;
  private aterm.ATerm pattern_VirtualKey_VK_SLASH;
  private aterm.AFun fun_VirtualKey_VK_SPACE;
  private aterm.ATerm pattern_VirtualKey_VK_SPACE;
  private aterm.AFun fun_VirtualKey_VK_SUBTRACT;
  private aterm.ATerm pattern_VirtualKey_VK_SUBTRACT;
  private aterm.AFun fun_VirtualKey_VK_TAB;
  private aterm.ATerm pattern_VirtualKey_VK_TAB;
  private aterm.AFun fun_VirtualKey_VK_UNDERSCORE;
  private aterm.ATerm pattern_VirtualKey_VK_UNDERSCORE;
  private aterm.AFun fun_VirtualKey_VK_UP;
  private aterm.ATerm pattern_VirtualKey_VK_UP;

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

    pattern_KeyModifier_M_ALT = factory.parse("M_ALT");
    fun_KeyModifier_M_ALT = factory.makeAFun("_KeyModifier_M_ALT", 0, false);

    pattern_KeyModifier_M_CTRL = factory.parse("M_CTRL");
    fun_KeyModifier_M_CTRL = factory.makeAFun("_KeyModifier_M_CTRL", 0, false);

    pattern_KeyModifier_M_SHIFT = factory.parse("M_SHIFT");
    fun_KeyModifier_M_SHIFT = factory.makeAFun("_KeyModifier_M_SHIFT", 0, false);

    pattern_VirtualKey_VK_0 = factory.parse("VK_0");
    fun_VirtualKey_VK_0 = factory.makeAFun("_VirtualKey_VK_0", 0, false);

    pattern_VirtualKey_VK_1 = factory.parse("VK_1");
    fun_VirtualKey_VK_1 = factory.makeAFun("_VirtualKey_VK_1", 0, false);

    pattern_VirtualKey_VK_2 = factory.parse("VK_2");
    fun_VirtualKey_VK_2 = factory.makeAFun("_VirtualKey_VK_2", 0, false);

    pattern_VirtualKey_VK_3 = factory.parse("VK_3");
    fun_VirtualKey_VK_3 = factory.makeAFun("_VirtualKey_VK_3", 0, false);

    pattern_VirtualKey_VK_4 = factory.parse("VK_4");
    fun_VirtualKey_VK_4 = factory.makeAFun("_VirtualKey_VK_4", 0, false);

    pattern_VirtualKey_VK_5 = factory.parse("VK_5");
    fun_VirtualKey_VK_5 = factory.makeAFun("_VirtualKey_VK_5", 0, false);

    pattern_VirtualKey_VK_6 = factory.parse("VK_6");
    fun_VirtualKey_VK_6 = factory.makeAFun("_VirtualKey_VK_6", 0, false);

    pattern_VirtualKey_VK_7 = factory.parse("VK_7");
    fun_VirtualKey_VK_7 = factory.makeAFun("_VirtualKey_VK_7", 0, false);

    pattern_VirtualKey_VK_8 = factory.parse("VK_8");
    fun_VirtualKey_VK_8 = factory.makeAFun("_VirtualKey_VK_8", 0, false);

    pattern_VirtualKey_VK_9 = factory.parse("VK_9");
    fun_VirtualKey_VK_9 = factory.makeAFun("_VirtualKey_VK_9", 0, false);

    pattern_VirtualKey_VK_A = factory.parse("VK_A");
    fun_VirtualKey_VK_A = factory.makeAFun("_VirtualKey_VK_A", 0, false);

    pattern_VirtualKey_VK_B = factory.parse("VK_B");
    fun_VirtualKey_VK_B = factory.makeAFun("_VirtualKey_VK_B", 0, false);

    pattern_VirtualKey_VK_C = factory.parse("VK_C");
    fun_VirtualKey_VK_C = factory.makeAFun("_VirtualKey_VK_C", 0, false);

    pattern_VirtualKey_VK_D = factory.parse("VK_D");
    fun_VirtualKey_VK_D = factory.makeAFun("_VirtualKey_VK_D", 0, false);

    pattern_VirtualKey_VK_E = factory.parse("VK_E");
    fun_VirtualKey_VK_E = factory.makeAFun("_VirtualKey_VK_E", 0, false);

    pattern_VirtualKey_VK_F = factory.parse("VK_F");
    fun_VirtualKey_VK_F = factory.makeAFun("_VirtualKey_VK_F", 0, false);

    pattern_VirtualKey_VK_G = factory.parse("VK_G");
    fun_VirtualKey_VK_G = factory.makeAFun("_VirtualKey_VK_G", 0, false);

    pattern_VirtualKey_VK_H = factory.parse("VK_H");
    fun_VirtualKey_VK_H = factory.makeAFun("_VirtualKey_VK_H", 0, false);

    pattern_VirtualKey_VK_I = factory.parse("VK_I");
    fun_VirtualKey_VK_I = factory.makeAFun("_VirtualKey_VK_I", 0, false);

    pattern_VirtualKey_VK_J = factory.parse("VK_J");
    fun_VirtualKey_VK_J = factory.makeAFun("_VirtualKey_VK_J", 0, false);

    pattern_VirtualKey_VK_K = factory.parse("VK_K");
    fun_VirtualKey_VK_K = factory.makeAFun("_VirtualKey_VK_K", 0, false);

    pattern_VirtualKey_VK_L = factory.parse("VK_L");
    fun_VirtualKey_VK_L = factory.makeAFun("_VirtualKey_VK_L", 0, false);

    pattern_VirtualKey_VK_M = factory.parse("VK_M");
    fun_VirtualKey_VK_M = factory.makeAFun("_VirtualKey_VK_M", 0, false);

    pattern_VirtualKey_VK_N = factory.parse("VK_N");
    fun_VirtualKey_VK_N = factory.makeAFun("_VirtualKey_VK_N", 0, false);

    pattern_VirtualKey_VK_O = factory.parse("VK_O");
    fun_VirtualKey_VK_O = factory.makeAFun("_VirtualKey_VK_O", 0, false);

    pattern_VirtualKey_VK_P = factory.parse("VK_P");
    fun_VirtualKey_VK_P = factory.makeAFun("_VirtualKey_VK_P", 0, false);

    pattern_VirtualKey_VK_Q = factory.parse("VK_Q");
    fun_VirtualKey_VK_Q = factory.makeAFun("_VirtualKey_VK_Q", 0, false);

    pattern_VirtualKey_VK_R = factory.parse("VK_R");
    fun_VirtualKey_VK_R = factory.makeAFun("_VirtualKey_VK_R", 0, false);

    pattern_VirtualKey_VK_S = factory.parse("VK_S");
    fun_VirtualKey_VK_S = factory.makeAFun("_VirtualKey_VK_S", 0, false);

    pattern_VirtualKey_VK_T = factory.parse("VK_T");
    fun_VirtualKey_VK_T = factory.makeAFun("_VirtualKey_VK_T", 0, false);

    pattern_VirtualKey_VK_U = factory.parse("VK_U");
    fun_VirtualKey_VK_U = factory.makeAFun("_VirtualKey_VK_U", 0, false);

    pattern_VirtualKey_VK_V = factory.parse("VK_V");
    fun_VirtualKey_VK_V = factory.makeAFun("_VirtualKey_VK_V", 0, false);

    pattern_VirtualKey_VK_W = factory.parse("VK_W");
    fun_VirtualKey_VK_W = factory.makeAFun("_VirtualKey_VK_W", 0, false);

    pattern_VirtualKey_VK_X = factory.parse("VK_X");
    fun_VirtualKey_VK_X = factory.makeAFun("_VirtualKey_VK_X", 0, false);

    pattern_VirtualKey_VK_Y = factory.parse("VK_Y");
    fun_VirtualKey_VK_Y = factory.makeAFun("_VirtualKey_VK_Y", 0, false);

    pattern_VirtualKey_VK_Z = factory.parse("VK_Z");
    fun_VirtualKey_VK_Z = factory.makeAFun("_VirtualKey_VK_Z", 0, false);

    pattern_VirtualKey_VK_AMPERSAND = factory.parse("VK_AMPERSAND");
    fun_VirtualKey_VK_AMPERSAND = factory.makeAFun("_VirtualKey_VK_AMPERSAND", 0, false);

    pattern_VirtualKey_VK_ASTERISK = factory.parse("VK_ASTERISK");
    fun_VirtualKey_VK_ASTERISK = factory.makeAFun("_VirtualKey_VK_ASTERISK", 0, false);

    pattern_VirtualKey_VK_AT = factory.parse("VK_AT");
    fun_VirtualKey_VK_AT = factory.makeAFun("_VirtualKey_VK_AT", 0, false);

    pattern_VirtualKey_VK_BACK_QUOTE = factory.parse("VK_BACK_QUOTE");
    fun_VirtualKey_VK_BACK_QUOTE = factory.makeAFun("_VirtualKey_VK_BACK_QUOTE", 0, false);

    pattern_VirtualKey_VK_BACK_SLASH = factory.parse("VK_BACK_SLASH");
    fun_VirtualKey_VK_BACK_SLASH = factory.makeAFun("_VirtualKey_VK_BACK_SLASH", 0, false);

    pattern_VirtualKey_VK_BACK_SPACE = factory.parse("VK_BACK_SPACE");
    fun_VirtualKey_VK_BACK_SPACE = factory.makeAFun("_VirtualKey_VK_BACK_SPACE", 0, false);

    pattern_VirtualKey_VK_BEGIN = factory.parse("VK_BEGIN");
    fun_VirtualKey_VK_BEGIN = factory.makeAFun("_VirtualKey_VK_BEGIN", 0, false);

    pattern_VirtualKey_VK_BRACE_LEFT = factory.parse("VK_BRACE_LEFT");
    fun_VirtualKey_VK_BRACE_LEFT = factory.makeAFun("_VirtualKey_VK_BRACE_LEFT", 0, false);

    pattern_VirtualKey_VK_BRACE_RIGHT = factory.parse("VK_BRACE_RIGHT");
    fun_VirtualKey_VK_BRACE_RIGHT = factory.makeAFun("_VirtualKey_VK_BRACE_RIGHT", 0, false);

    pattern_VirtualKey_VK_CIRCUMFLEX = factory.parse("VK_CIRCUMFLEX");
    fun_VirtualKey_VK_CIRCUMFLEX = factory.makeAFun("_VirtualKey_VK_CIRCUMFLEX", 0, false);

    pattern_VirtualKey_VK_CLEAR = factory.parse("VK_CLEAR");
    fun_VirtualKey_VK_CLEAR = factory.makeAFun("_VirtualKey_VK_CLEAR", 0, false);

    pattern_VirtualKey_VK_CLOSE_BRACKET = factory.parse("VK_CLOSE_BRACKET");
    fun_VirtualKey_VK_CLOSE_BRACKET = factory.makeAFun("_VirtualKey_VK_CLOSE_BRACKET", 0, false);

    pattern_VirtualKey_VK_COLON = factory.parse("VK_COLON");
    fun_VirtualKey_VK_COLON = factory.makeAFun("_VirtualKey_VK_COLON", 0, false);

    pattern_VirtualKey_VK_COMMA = factory.parse("VK_COMMA");
    fun_VirtualKey_VK_COMMA = factory.makeAFun("_VirtualKey_VK_COMMA", 0, false);

    pattern_VirtualKey_VK_DECIMAL = factory.parse("VK_DECIMAL");
    fun_VirtualKey_VK_DECIMAL = factory.makeAFun("_VirtualKey_VK_DECIMAL", 0, false);

    pattern_VirtualKey_VK_DELETE = factory.parse("VK_DELETE");
    fun_VirtualKey_VK_DELETE = factory.makeAFun("_VirtualKey_VK_DELETE", 0, false);

    pattern_VirtualKey_VK_DIVIDE = factory.parse("VK_DIVIDE");
    fun_VirtualKey_VK_DIVIDE = factory.makeAFun("_VirtualKey_VK_DIVIDE", 0, false);

    pattern_VirtualKey_VK_DOLLAR = factory.parse("VK_DOLLAR");
    fun_VirtualKey_VK_DOLLAR = factory.makeAFun("_VirtualKey_VK_DOLLAR", 0, false);

    pattern_VirtualKey_VK_DOWN = factory.parse("VK_DOWN");
    fun_VirtualKey_VK_DOWN = factory.makeAFun("_VirtualKey_VK_DOWN", 0, false);

    pattern_VirtualKey_VK_END = factory.parse("VK_END");
    fun_VirtualKey_VK_END = factory.makeAFun("_VirtualKey_VK_END", 0, false);

    pattern_VirtualKey_VK_ENTER = factory.parse("VK_ENTER");
    fun_VirtualKey_VK_ENTER = factory.makeAFun("_VirtualKey_VK_ENTER", 0, false);

    pattern_VirtualKey_VK_EQUALS = factory.parse("VK_EQUALS");
    fun_VirtualKey_VK_EQUALS = factory.makeAFun("_VirtualKey_VK_EQUALS", 0, false);

    pattern_VirtualKey_VK_ESCAPE = factory.parse("VK_ESCAPE");
    fun_VirtualKey_VK_ESCAPE = factory.makeAFun("_VirtualKey_VK_ESCAPE", 0, false);

    pattern_VirtualKey_VK_EXCLAMATION_MARK = factory.parse("VK_EXCLAMATION_MARK");
    fun_VirtualKey_VK_EXCLAMATION_MARK = factory.makeAFun("_VirtualKey_VK_EXCLAMATION_MARK", 0, false);

    pattern_VirtualKey_VK_F1 = factory.parse("VK_F1");
    fun_VirtualKey_VK_F1 = factory.makeAFun("_VirtualKey_VK_F1", 0, false);

    pattern_VirtualKey_VK_F2 = factory.parse("VK_F2");
    fun_VirtualKey_VK_F2 = factory.makeAFun("_VirtualKey_VK_F2", 0, false);

    pattern_VirtualKey_VK_F3 = factory.parse("VK_F3");
    fun_VirtualKey_VK_F3 = factory.makeAFun("_VirtualKey_VK_F3", 0, false);

    pattern_VirtualKey_VK_F4 = factory.parse("VK_F4");
    fun_VirtualKey_VK_F4 = factory.makeAFun("_VirtualKey_VK_F4", 0, false);

    pattern_VirtualKey_VK_F5 = factory.parse("VK_F5");
    fun_VirtualKey_VK_F5 = factory.makeAFun("_VirtualKey_VK_F5", 0, false);

    pattern_VirtualKey_VK_F6 = factory.parse("VK_F6");
    fun_VirtualKey_VK_F6 = factory.makeAFun("_VirtualKey_VK_F6", 0, false);

    pattern_VirtualKey_VK_F7 = factory.parse("VK_F7");
    fun_VirtualKey_VK_F7 = factory.makeAFun("_VirtualKey_VK_F7", 0, false);

    pattern_VirtualKey_VK_F8 = factory.parse("VK_F8");
    fun_VirtualKey_VK_F8 = factory.makeAFun("_VirtualKey_VK_F8", 0, false);

    pattern_VirtualKey_VK_F9 = factory.parse("VK_F9");
    fun_VirtualKey_VK_F9 = factory.makeAFun("_VirtualKey_VK_F9", 0, false);

    pattern_VirtualKey_VK_F10 = factory.parse("VK_F10");
    fun_VirtualKey_VK_F10 = factory.makeAFun("_VirtualKey_VK_F10", 0, false);

    pattern_VirtualKey_VK_F11 = factory.parse("VK_F11");
    fun_VirtualKey_VK_F11 = factory.makeAFun("_VirtualKey_VK_F11", 0, false);

    pattern_VirtualKey_VK_F12 = factory.parse("VK_F12");
    fun_VirtualKey_VK_F12 = factory.makeAFun("_VirtualKey_VK_F12", 0, false);

    pattern_VirtualKey_VK_GREATER = factory.parse("VK_GREATER");
    fun_VirtualKey_VK_GREATER = factory.makeAFun("_VirtualKey_VK_GREATER", 0, false);

    pattern_VirtualKey_VK_HOME = factory.parse("VK_HOME");
    fun_VirtualKey_VK_HOME = factory.makeAFun("_VirtualKey_VK_HOME", 0, false);

    pattern_VirtualKey_VK_INSERT = factory.parse("VK_INSERT");
    fun_VirtualKey_VK_INSERT = factory.makeAFun("_VirtualKey_VK_INSERT", 0, false);

    pattern_VirtualKey_VK_LEFT = factory.parse("VK_LEFT");
    fun_VirtualKey_VK_LEFT = factory.makeAFun("_VirtualKey_VK_LEFT", 0, false);

    pattern_VirtualKey_VK_LEFT_PARENTHESIS = factory.parse("VK_LEFT_PARENTHESIS");
    fun_VirtualKey_VK_LEFT_PARENTHESIS = factory.makeAFun("_VirtualKey_VK_LEFT_PARENTHESIS", 0, false);

    pattern_VirtualKey_VK_MINUS = factory.parse("VK_MINUS");
    fun_VirtualKey_VK_MINUS = factory.makeAFun("_VirtualKey_VK_MINUS", 0, false);

    pattern_VirtualKey_VK_MULTIPLY = factory.parse("VK_MULTIPLY");
    fun_VirtualKey_VK_MULTIPLY = factory.makeAFun("_VirtualKey_VK_MULTIPLY", 0, false);

    pattern_VirtualKey_VK_NUMBER_SIGN = factory.parse("VK_NUMBER_SIGN");
    fun_VirtualKey_VK_NUMBER_SIGN = factory.makeAFun("_VirtualKey_VK_NUMBER_SIGN", 0, false);

    pattern_VirtualKey_VK_OPEN_BRACKET = factory.parse("VK_OPEN_BRACKET");
    fun_VirtualKey_VK_OPEN_BRACKET = factory.makeAFun("_VirtualKey_VK_OPEN_BRACKET", 0, false);

    pattern_VirtualKey_VK_PAGE_DOWN = factory.parse("VK_PAGE_DOWN");
    fun_VirtualKey_VK_PAGE_DOWN = factory.makeAFun("_VirtualKey_VK_PAGE_DOWN", 0, false);

    pattern_VirtualKey_VK_PAGE_UP = factory.parse("VK_PAGE_UP");
    fun_VirtualKey_VK_PAGE_UP = factory.makeAFun("_VirtualKey_VK_PAGE_UP", 0, false);

    pattern_VirtualKey_VK_PAUSE = factory.parse("VK_PAUSE");
    fun_VirtualKey_VK_PAUSE = factory.makeAFun("_VirtualKey_VK_PAUSE", 0, false);

    pattern_VirtualKey_VK_PERIOD = factory.parse("VK_PERIOD");
    fun_VirtualKey_VK_PERIOD = factory.makeAFun("_VirtualKey_VK_PERIOD", 0, false);

    pattern_VirtualKey_VK_PLUS = factory.parse("VK_PLUS");
    fun_VirtualKey_VK_PLUS = factory.makeAFun("_VirtualKey_VK_PLUS", 0, false);

    pattern_VirtualKey_VK_PRINTSCREEN = factory.parse("VK_PRINTSCREEN");
    fun_VirtualKey_VK_PRINTSCREEN = factory.makeAFun("_VirtualKey_VK_PRINTSCREEN", 0, false);

    pattern_VirtualKey_VK_QUOTE = factory.parse("VK_QUOTE");
    fun_VirtualKey_VK_QUOTE = factory.makeAFun("_VirtualKey_VK_QUOTE", 0, false);

    pattern_VirtualKey_VK_QUOTEDBL = factory.parse("VK_QUOTEDBL");
    fun_VirtualKey_VK_QUOTEDBL = factory.makeAFun("_VirtualKey_VK_QUOTEDBL", 0, false);

    pattern_VirtualKey_VK_RIGHT = factory.parse("VK_RIGHT");
    fun_VirtualKey_VK_RIGHT = factory.makeAFun("_VirtualKey_VK_RIGHT", 0, false);

    pattern_VirtualKey_VK_RIGHT_PARENTHESIS = factory.parse("VK_RIGHT_PARENTHESIS");
    fun_VirtualKey_VK_RIGHT_PARENTHESIS = factory.makeAFun("_VirtualKey_VK_RIGHT_PARENTHESIS", 0, false);

    pattern_VirtualKey_VK_SEMICOLON = factory.parse("VK_SEMICOLON");
    fun_VirtualKey_VK_SEMICOLON = factory.makeAFun("_VirtualKey_VK_SEMICOLON", 0, false);

    pattern_VirtualKey_VK_SLASH = factory.parse("VK_SLASH");
    fun_VirtualKey_VK_SLASH = factory.makeAFun("_VirtualKey_VK_SLASH", 0, false);

    pattern_VirtualKey_VK_SPACE = factory.parse("VK_SPACE");
    fun_VirtualKey_VK_SPACE = factory.makeAFun("_VirtualKey_VK_SPACE", 0, false);

    pattern_VirtualKey_VK_SUBTRACT = factory.parse("VK_SUBTRACT");
    fun_VirtualKey_VK_SUBTRACT = factory.makeAFun("_VirtualKey_VK_SUBTRACT", 0, false);

    pattern_VirtualKey_VK_TAB = factory.parse("VK_TAB");
    fun_VirtualKey_VK_TAB = factory.makeAFun("_VirtualKey_VK_TAB", 0, false);

    pattern_VirtualKey_VK_UNDERSCORE = factory.parse("VK_UNDERSCORE");
    fun_VirtualKey_VK_UNDERSCORE = factory.makeAFun("_VirtualKey_VK_UNDERSCORE", 0, false);

    pattern_VirtualKey_VK_UP = factory.parse("VK_UP");
    fun_VirtualKey_VK_UP = factory.makeAFun("_VirtualKey_VK_UP", 0, false);

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

  public nl.cwi.sen1.configapi.types.keymodifier.M_ALT makeKeyModifier_M_ALT(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.keymodifier.M_ALT) factory.build( new nl.cwi.sen1.configapi.types.keymodifier.M_ALT(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.keymodifier.M_ALT makeKeyModifier_M_ALT() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeKeyModifier_M_ALT(fun_KeyModifier_M_ALT, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.KeyModifier KeyModifier_M_ALTFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_KeyModifier_M_ALT);

    if (children != null) {
      return makeKeyModifier_M_ALT(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.keymodifier.M_ALT arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_KeyModifier_M_ALT, args);
  }

  public nl.cwi.sen1.configapi.types.keymodifier.M_CTRL makeKeyModifier_M_CTRL(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.keymodifier.M_CTRL) factory.build( new nl.cwi.sen1.configapi.types.keymodifier.M_CTRL(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.keymodifier.M_CTRL makeKeyModifier_M_CTRL() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeKeyModifier_M_CTRL(fun_KeyModifier_M_CTRL, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.KeyModifier KeyModifier_M_CTRLFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_KeyModifier_M_CTRL);

    if (children != null) {
      return makeKeyModifier_M_CTRL(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.keymodifier.M_CTRL arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_KeyModifier_M_CTRL, args);
  }

  public nl.cwi.sen1.configapi.types.keymodifier.M_SHIFT makeKeyModifier_M_SHIFT(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.keymodifier.M_SHIFT) factory.build( new nl.cwi.sen1.configapi.types.keymodifier.M_SHIFT(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.keymodifier.M_SHIFT makeKeyModifier_M_SHIFT() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeKeyModifier_M_SHIFT(fun_KeyModifier_M_SHIFT, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.KeyModifier KeyModifier_M_SHIFTFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_KeyModifier_M_SHIFT);

    if (children != null) {
      return makeKeyModifier_M_SHIFT(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.keymodifier.M_SHIFT arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_KeyModifier_M_SHIFT, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_0 makeVirtualKey_VK_0(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_0) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_0(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_0 makeVirtualKey_VK_0() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_0(fun_VirtualKey_VK_0, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_0FromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_0);

    if (children != null) {
      return makeVirtualKey_VK_0(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_0 arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_0, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_1 makeVirtualKey_VK_1(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_1) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_1(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_1 makeVirtualKey_VK_1() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_1(fun_VirtualKey_VK_1, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_1FromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_1);

    if (children != null) {
      return makeVirtualKey_VK_1(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_1 arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_1, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_2 makeVirtualKey_VK_2(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_2) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_2(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_2 makeVirtualKey_VK_2() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_2(fun_VirtualKey_VK_2, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_2FromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_2);

    if (children != null) {
      return makeVirtualKey_VK_2(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_2 arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_2, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_3 makeVirtualKey_VK_3(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_3) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_3(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_3 makeVirtualKey_VK_3() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_3(fun_VirtualKey_VK_3, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_3FromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_3);

    if (children != null) {
      return makeVirtualKey_VK_3(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_3 arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_3, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_4 makeVirtualKey_VK_4(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_4) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_4(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_4 makeVirtualKey_VK_4() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_4(fun_VirtualKey_VK_4, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_4FromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_4);

    if (children != null) {
      return makeVirtualKey_VK_4(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_4 arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_4, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_5 makeVirtualKey_VK_5(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_5) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_5(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_5 makeVirtualKey_VK_5() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_5(fun_VirtualKey_VK_5, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_5FromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_5);

    if (children != null) {
      return makeVirtualKey_VK_5(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_5 arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_5, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_6 makeVirtualKey_VK_6(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_6) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_6(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_6 makeVirtualKey_VK_6() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_6(fun_VirtualKey_VK_6, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_6FromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_6);

    if (children != null) {
      return makeVirtualKey_VK_6(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_6 arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_6, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_7 makeVirtualKey_VK_7(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_7) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_7(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_7 makeVirtualKey_VK_7() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_7(fun_VirtualKey_VK_7, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_7FromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_7);

    if (children != null) {
      return makeVirtualKey_VK_7(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_7 arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_7, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_8 makeVirtualKey_VK_8(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_8) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_8(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_8 makeVirtualKey_VK_8() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_8(fun_VirtualKey_VK_8, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_8FromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_8);

    if (children != null) {
      return makeVirtualKey_VK_8(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_8 arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_8, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_9 makeVirtualKey_VK_9(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_9) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_9(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_9 makeVirtualKey_VK_9() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_9(fun_VirtualKey_VK_9, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_9FromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_9);

    if (children != null) {
      return makeVirtualKey_VK_9(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_9 arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_9, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_A makeVirtualKey_VK_A(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_A) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_A(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_A makeVirtualKey_VK_A() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_A(fun_VirtualKey_VK_A, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_AFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_A);

    if (children != null) {
      return makeVirtualKey_VK_A(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_A arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_A, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_B makeVirtualKey_VK_B(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_B) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_B(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_B makeVirtualKey_VK_B() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_B(fun_VirtualKey_VK_B, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_BFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_B);

    if (children != null) {
      return makeVirtualKey_VK_B(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_B arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_B, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_C makeVirtualKey_VK_C(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_C) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_C(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_C makeVirtualKey_VK_C() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_C(fun_VirtualKey_VK_C, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_CFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_C);

    if (children != null) {
      return makeVirtualKey_VK_C(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_C arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_C, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_D makeVirtualKey_VK_D(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_D) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_D(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_D makeVirtualKey_VK_D() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_D(fun_VirtualKey_VK_D, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_DFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_D);

    if (children != null) {
      return makeVirtualKey_VK_D(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_D arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_D, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_E makeVirtualKey_VK_E(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_E) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_E(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_E makeVirtualKey_VK_E() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_E(fun_VirtualKey_VK_E, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_EFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_E);

    if (children != null) {
      return makeVirtualKey_VK_E(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_E arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_E, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_F makeVirtualKey_VK_F(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_F) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_F(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_F makeVirtualKey_VK_F() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_F(fun_VirtualKey_VK_F, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_FFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_F);

    if (children != null) {
      return makeVirtualKey_VK_F(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_F arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_F, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_G makeVirtualKey_VK_G(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_G) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_G(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_G makeVirtualKey_VK_G() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_G(fun_VirtualKey_VK_G, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_GFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_G);

    if (children != null) {
      return makeVirtualKey_VK_G(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_G arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_G, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_H makeVirtualKey_VK_H(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_H) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_H(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_H makeVirtualKey_VK_H() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_H(fun_VirtualKey_VK_H, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_HFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_H);

    if (children != null) {
      return makeVirtualKey_VK_H(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_H arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_H, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_I makeVirtualKey_VK_I(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_I) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_I(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_I makeVirtualKey_VK_I() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_I(fun_VirtualKey_VK_I, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_IFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_I);

    if (children != null) {
      return makeVirtualKey_VK_I(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_I arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_I, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_J makeVirtualKey_VK_J(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_J) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_J(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_J makeVirtualKey_VK_J() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_J(fun_VirtualKey_VK_J, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_JFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_J);

    if (children != null) {
      return makeVirtualKey_VK_J(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_J arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_J, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_K makeVirtualKey_VK_K(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_K) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_K(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_K makeVirtualKey_VK_K() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_K(fun_VirtualKey_VK_K, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_KFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_K);

    if (children != null) {
      return makeVirtualKey_VK_K(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_K arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_K, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_L makeVirtualKey_VK_L(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_L) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_L(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_L makeVirtualKey_VK_L() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_L(fun_VirtualKey_VK_L, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_LFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_L);

    if (children != null) {
      return makeVirtualKey_VK_L(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_L arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_L, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_M makeVirtualKey_VK_M(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_M) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_M(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_M makeVirtualKey_VK_M() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_M(fun_VirtualKey_VK_M, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_MFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_M);

    if (children != null) {
      return makeVirtualKey_VK_M(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_M arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_M, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_N makeVirtualKey_VK_N(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_N) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_N(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_N makeVirtualKey_VK_N() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_N(fun_VirtualKey_VK_N, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_NFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_N);

    if (children != null) {
      return makeVirtualKey_VK_N(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_N arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_N, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_O makeVirtualKey_VK_O(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_O) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_O(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_O makeVirtualKey_VK_O() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_O(fun_VirtualKey_VK_O, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_OFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_O);

    if (children != null) {
      return makeVirtualKey_VK_O(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_O arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_O, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_P makeVirtualKey_VK_P(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_P) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_P(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_P makeVirtualKey_VK_P() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_P(fun_VirtualKey_VK_P, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_PFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_P);

    if (children != null) {
      return makeVirtualKey_VK_P(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_P arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_P, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_Q makeVirtualKey_VK_Q(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_Q) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_Q(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_Q makeVirtualKey_VK_Q() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_Q(fun_VirtualKey_VK_Q, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_QFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_Q);

    if (children != null) {
      return makeVirtualKey_VK_Q(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_Q arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_Q, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_R makeVirtualKey_VK_R(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_R) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_R(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_R makeVirtualKey_VK_R() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_R(fun_VirtualKey_VK_R, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_RFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_R);

    if (children != null) {
      return makeVirtualKey_VK_R(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_R arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_R, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_S makeVirtualKey_VK_S(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_S) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_S(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_S makeVirtualKey_VK_S() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_S(fun_VirtualKey_VK_S, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_SFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_S);

    if (children != null) {
      return makeVirtualKey_VK_S(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_S arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_S, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_T makeVirtualKey_VK_T(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_T) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_T(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_T makeVirtualKey_VK_T() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_T(fun_VirtualKey_VK_T, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_TFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_T);

    if (children != null) {
      return makeVirtualKey_VK_T(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_T arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_T, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_U makeVirtualKey_VK_U(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_U) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_U(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_U makeVirtualKey_VK_U() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_U(fun_VirtualKey_VK_U, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_UFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_U);

    if (children != null) {
      return makeVirtualKey_VK_U(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_U arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_U, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_V makeVirtualKey_VK_V(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_V) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_V(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_V makeVirtualKey_VK_V() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_V(fun_VirtualKey_VK_V, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_VFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_V);

    if (children != null) {
      return makeVirtualKey_VK_V(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_V arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_V, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_W makeVirtualKey_VK_W(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_W) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_W(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_W makeVirtualKey_VK_W() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_W(fun_VirtualKey_VK_W, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_WFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_W);

    if (children != null) {
      return makeVirtualKey_VK_W(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_W arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_W, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_X makeVirtualKey_VK_X(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_X) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_X(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_X makeVirtualKey_VK_X() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_X(fun_VirtualKey_VK_X, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_XFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_X);

    if (children != null) {
      return makeVirtualKey_VK_X(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_X arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_X, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_Y makeVirtualKey_VK_Y(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_Y) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_Y(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_Y makeVirtualKey_VK_Y() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_Y(fun_VirtualKey_VK_Y, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_YFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_Y);

    if (children != null) {
      return makeVirtualKey_VK_Y(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_Y arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_Y, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_Z makeVirtualKey_VK_Z(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_Z) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_Z(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_Z makeVirtualKey_VK_Z() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_Z(fun_VirtualKey_VK_Z, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_ZFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_Z);

    if (children != null) {
      return makeVirtualKey_VK_Z(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_Z arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_Z, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_AMPERSAND makeVirtualKey_VK_AMPERSAND(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_AMPERSAND) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_AMPERSAND(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_AMPERSAND makeVirtualKey_VK_AMPERSAND() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_AMPERSAND(fun_VirtualKey_VK_AMPERSAND, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_AMPERSANDFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_AMPERSAND);

    if (children != null) {
      return makeVirtualKey_VK_AMPERSAND(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_AMPERSAND arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_AMPERSAND, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_ASTERISK makeVirtualKey_VK_ASTERISK(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_ASTERISK) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_ASTERISK(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_ASTERISK makeVirtualKey_VK_ASTERISK() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_ASTERISK(fun_VirtualKey_VK_ASTERISK, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_ASTERISKFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_ASTERISK);

    if (children != null) {
      return makeVirtualKey_VK_ASTERISK(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_ASTERISK arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_ASTERISK, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_AT makeVirtualKey_VK_AT(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_AT) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_AT(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_AT makeVirtualKey_VK_AT() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_AT(fun_VirtualKey_VK_AT, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_ATFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_AT);

    if (children != null) {
      return makeVirtualKey_VK_AT(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_AT arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_AT, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_BACK_QUOTE makeVirtualKey_VK_BACK_QUOTE(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_BACK_QUOTE) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_BACK_QUOTE(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_BACK_QUOTE makeVirtualKey_VK_BACK_QUOTE() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_BACK_QUOTE(fun_VirtualKey_VK_BACK_QUOTE, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_BACK_QUOTEFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_BACK_QUOTE);

    if (children != null) {
      return makeVirtualKey_VK_BACK_QUOTE(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_BACK_QUOTE arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_BACK_QUOTE, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_BACK_SLASH makeVirtualKey_VK_BACK_SLASH(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_BACK_SLASH) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_BACK_SLASH(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_BACK_SLASH makeVirtualKey_VK_BACK_SLASH() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_BACK_SLASH(fun_VirtualKey_VK_BACK_SLASH, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_BACK_SLASHFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_BACK_SLASH);

    if (children != null) {
      return makeVirtualKey_VK_BACK_SLASH(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_BACK_SLASH arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_BACK_SLASH, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_BACK_SPACE makeVirtualKey_VK_BACK_SPACE(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_BACK_SPACE) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_BACK_SPACE(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_BACK_SPACE makeVirtualKey_VK_BACK_SPACE() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_BACK_SPACE(fun_VirtualKey_VK_BACK_SPACE, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_BACK_SPACEFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_BACK_SPACE);

    if (children != null) {
      return makeVirtualKey_VK_BACK_SPACE(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_BACK_SPACE arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_BACK_SPACE, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_BEGIN makeVirtualKey_VK_BEGIN(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_BEGIN) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_BEGIN(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_BEGIN makeVirtualKey_VK_BEGIN() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_BEGIN(fun_VirtualKey_VK_BEGIN, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_BEGINFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_BEGIN);

    if (children != null) {
      return makeVirtualKey_VK_BEGIN(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_BEGIN arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_BEGIN, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_BRACE_LEFT makeVirtualKey_VK_BRACE_LEFT(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_BRACE_LEFT) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_BRACE_LEFT(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_BRACE_LEFT makeVirtualKey_VK_BRACE_LEFT() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_BRACE_LEFT(fun_VirtualKey_VK_BRACE_LEFT, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_BRACE_LEFTFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_BRACE_LEFT);

    if (children != null) {
      return makeVirtualKey_VK_BRACE_LEFT(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_BRACE_LEFT arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_BRACE_LEFT, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_BRACE_RIGHT makeVirtualKey_VK_BRACE_RIGHT(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_BRACE_RIGHT) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_BRACE_RIGHT(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_BRACE_RIGHT makeVirtualKey_VK_BRACE_RIGHT() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_BRACE_RIGHT(fun_VirtualKey_VK_BRACE_RIGHT, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_BRACE_RIGHTFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_BRACE_RIGHT);

    if (children != null) {
      return makeVirtualKey_VK_BRACE_RIGHT(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_BRACE_RIGHT arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_BRACE_RIGHT, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_CIRCUMFLEX makeVirtualKey_VK_CIRCUMFLEX(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_CIRCUMFLEX) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_CIRCUMFLEX(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_CIRCUMFLEX makeVirtualKey_VK_CIRCUMFLEX() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_CIRCUMFLEX(fun_VirtualKey_VK_CIRCUMFLEX, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_CIRCUMFLEXFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_CIRCUMFLEX);

    if (children != null) {
      return makeVirtualKey_VK_CIRCUMFLEX(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_CIRCUMFLEX arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_CIRCUMFLEX, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_CLEAR makeVirtualKey_VK_CLEAR(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_CLEAR) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_CLEAR(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_CLEAR makeVirtualKey_VK_CLEAR() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_CLEAR(fun_VirtualKey_VK_CLEAR, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_CLEARFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_CLEAR);

    if (children != null) {
      return makeVirtualKey_VK_CLEAR(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_CLEAR arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_CLEAR, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_CLOSE_BRACKET makeVirtualKey_VK_CLOSE_BRACKET(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_CLOSE_BRACKET) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_CLOSE_BRACKET(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_CLOSE_BRACKET makeVirtualKey_VK_CLOSE_BRACKET() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_CLOSE_BRACKET(fun_VirtualKey_VK_CLOSE_BRACKET, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_CLOSE_BRACKETFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_CLOSE_BRACKET);

    if (children != null) {
      return makeVirtualKey_VK_CLOSE_BRACKET(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_CLOSE_BRACKET arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_CLOSE_BRACKET, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_COLON makeVirtualKey_VK_COLON(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_COLON) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_COLON(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_COLON makeVirtualKey_VK_COLON() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_COLON(fun_VirtualKey_VK_COLON, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_COLONFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_COLON);

    if (children != null) {
      return makeVirtualKey_VK_COLON(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_COLON arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_COLON, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_COMMA makeVirtualKey_VK_COMMA(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_COMMA) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_COMMA(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_COMMA makeVirtualKey_VK_COMMA() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_COMMA(fun_VirtualKey_VK_COMMA, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_COMMAFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_COMMA);

    if (children != null) {
      return makeVirtualKey_VK_COMMA(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_COMMA arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_COMMA, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_DECIMAL makeVirtualKey_VK_DECIMAL(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_DECIMAL) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_DECIMAL(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_DECIMAL makeVirtualKey_VK_DECIMAL() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_DECIMAL(fun_VirtualKey_VK_DECIMAL, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_DECIMALFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_DECIMAL);

    if (children != null) {
      return makeVirtualKey_VK_DECIMAL(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_DECIMAL arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_DECIMAL, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_DELETE makeVirtualKey_VK_DELETE(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_DELETE) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_DELETE(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_DELETE makeVirtualKey_VK_DELETE() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_DELETE(fun_VirtualKey_VK_DELETE, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_DELETEFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_DELETE);

    if (children != null) {
      return makeVirtualKey_VK_DELETE(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_DELETE arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_DELETE, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_DIVIDE makeVirtualKey_VK_DIVIDE(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_DIVIDE) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_DIVIDE(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_DIVIDE makeVirtualKey_VK_DIVIDE() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_DIVIDE(fun_VirtualKey_VK_DIVIDE, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_DIVIDEFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_DIVIDE);

    if (children != null) {
      return makeVirtualKey_VK_DIVIDE(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_DIVIDE arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_DIVIDE, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_DOLLAR makeVirtualKey_VK_DOLLAR(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_DOLLAR) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_DOLLAR(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_DOLLAR makeVirtualKey_VK_DOLLAR() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_DOLLAR(fun_VirtualKey_VK_DOLLAR, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_DOLLARFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_DOLLAR);

    if (children != null) {
      return makeVirtualKey_VK_DOLLAR(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_DOLLAR arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_DOLLAR, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_DOWN makeVirtualKey_VK_DOWN(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_DOWN) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_DOWN(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_DOWN makeVirtualKey_VK_DOWN() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_DOWN(fun_VirtualKey_VK_DOWN, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_DOWNFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_DOWN);

    if (children != null) {
      return makeVirtualKey_VK_DOWN(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_DOWN arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_DOWN, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_END makeVirtualKey_VK_END(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_END) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_END(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_END makeVirtualKey_VK_END() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_END(fun_VirtualKey_VK_END, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_ENDFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_END);

    if (children != null) {
      return makeVirtualKey_VK_END(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_END arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_END, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_ENTER makeVirtualKey_VK_ENTER(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_ENTER) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_ENTER(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_ENTER makeVirtualKey_VK_ENTER() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_ENTER(fun_VirtualKey_VK_ENTER, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_ENTERFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_ENTER);

    if (children != null) {
      return makeVirtualKey_VK_ENTER(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_ENTER arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_ENTER, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_EQUALS makeVirtualKey_VK_EQUALS(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_EQUALS) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_EQUALS(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_EQUALS makeVirtualKey_VK_EQUALS() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_EQUALS(fun_VirtualKey_VK_EQUALS, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_EQUALSFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_EQUALS);

    if (children != null) {
      return makeVirtualKey_VK_EQUALS(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_EQUALS arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_EQUALS, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_ESCAPE makeVirtualKey_VK_ESCAPE(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_ESCAPE) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_ESCAPE(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_ESCAPE makeVirtualKey_VK_ESCAPE() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_ESCAPE(fun_VirtualKey_VK_ESCAPE, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_ESCAPEFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_ESCAPE);

    if (children != null) {
      return makeVirtualKey_VK_ESCAPE(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_ESCAPE arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_ESCAPE, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_EXCLAMATION_MARK makeVirtualKey_VK_EXCLAMATION_MARK(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_EXCLAMATION_MARK) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_EXCLAMATION_MARK(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_EXCLAMATION_MARK makeVirtualKey_VK_EXCLAMATION_MARK() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_EXCLAMATION_MARK(fun_VirtualKey_VK_EXCLAMATION_MARK, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_EXCLAMATION_MARKFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_EXCLAMATION_MARK);

    if (children != null) {
      return makeVirtualKey_VK_EXCLAMATION_MARK(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_EXCLAMATION_MARK arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_EXCLAMATION_MARK, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_F1 makeVirtualKey_VK_F1(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_F1) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_F1(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_F1 makeVirtualKey_VK_F1() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_F1(fun_VirtualKey_VK_F1, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_F1FromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_F1);

    if (children != null) {
      return makeVirtualKey_VK_F1(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_F1 arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_F1, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_F2 makeVirtualKey_VK_F2(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_F2) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_F2(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_F2 makeVirtualKey_VK_F2() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_F2(fun_VirtualKey_VK_F2, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_F2FromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_F2);

    if (children != null) {
      return makeVirtualKey_VK_F2(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_F2 arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_F2, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_F3 makeVirtualKey_VK_F3(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_F3) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_F3(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_F3 makeVirtualKey_VK_F3() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_F3(fun_VirtualKey_VK_F3, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_F3FromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_F3);

    if (children != null) {
      return makeVirtualKey_VK_F3(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_F3 arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_F3, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_F4 makeVirtualKey_VK_F4(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_F4) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_F4(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_F4 makeVirtualKey_VK_F4() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_F4(fun_VirtualKey_VK_F4, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_F4FromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_F4);

    if (children != null) {
      return makeVirtualKey_VK_F4(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_F4 arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_F4, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_F5 makeVirtualKey_VK_F5(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_F5) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_F5(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_F5 makeVirtualKey_VK_F5() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_F5(fun_VirtualKey_VK_F5, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_F5FromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_F5);

    if (children != null) {
      return makeVirtualKey_VK_F5(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_F5 arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_F5, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_F6 makeVirtualKey_VK_F6(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_F6) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_F6(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_F6 makeVirtualKey_VK_F6() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_F6(fun_VirtualKey_VK_F6, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_F6FromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_F6);

    if (children != null) {
      return makeVirtualKey_VK_F6(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_F6 arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_F6, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_F7 makeVirtualKey_VK_F7(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_F7) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_F7(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_F7 makeVirtualKey_VK_F7() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_F7(fun_VirtualKey_VK_F7, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_F7FromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_F7);

    if (children != null) {
      return makeVirtualKey_VK_F7(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_F7 arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_F7, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_F8 makeVirtualKey_VK_F8(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_F8) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_F8(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_F8 makeVirtualKey_VK_F8() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_F8(fun_VirtualKey_VK_F8, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_F8FromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_F8);

    if (children != null) {
      return makeVirtualKey_VK_F8(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_F8 arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_F8, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_F9 makeVirtualKey_VK_F9(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_F9) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_F9(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_F9 makeVirtualKey_VK_F9() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_F9(fun_VirtualKey_VK_F9, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_F9FromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_F9);

    if (children != null) {
      return makeVirtualKey_VK_F9(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_F9 arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_F9, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_F10 makeVirtualKey_VK_F10(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_F10) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_F10(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_F10 makeVirtualKey_VK_F10() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_F10(fun_VirtualKey_VK_F10, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_F10FromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_F10);

    if (children != null) {
      return makeVirtualKey_VK_F10(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_F10 arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_F10, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_F11 makeVirtualKey_VK_F11(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_F11) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_F11(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_F11 makeVirtualKey_VK_F11() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_F11(fun_VirtualKey_VK_F11, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_F11FromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_F11);

    if (children != null) {
      return makeVirtualKey_VK_F11(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_F11 arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_F11, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_F12 makeVirtualKey_VK_F12(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_F12) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_F12(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_F12 makeVirtualKey_VK_F12() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_F12(fun_VirtualKey_VK_F12, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_F12FromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_F12);

    if (children != null) {
      return makeVirtualKey_VK_F12(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_F12 arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_F12, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_GREATER makeVirtualKey_VK_GREATER(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_GREATER) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_GREATER(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_GREATER makeVirtualKey_VK_GREATER() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_GREATER(fun_VirtualKey_VK_GREATER, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_GREATERFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_GREATER);

    if (children != null) {
      return makeVirtualKey_VK_GREATER(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_GREATER arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_GREATER, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_HOME makeVirtualKey_VK_HOME(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_HOME) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_HOME(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_HOME makeVirtualKey_VK_HOME() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_HOME(fun_VirtualKey_VK_HOME, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_HOMEFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_HOME);

    if (children != null) {
      return makeVirtualKey_VK_HOME(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_HOME arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_HOME, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_INSERT makeVirtualKey_VK_INSERT(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_INSERT) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_INSERT(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_INSERT makeVirtualKey_VK_INSERT() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_INSERT(fun_VirtualKey_VK_INSERT, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_INSERTFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_INSERT);

    if (children != null) {
      return makeVirtualKey_VK_INSERT(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_INSERT arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_INSERT, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_LEFT makeVirtualKey_VK_LEFT(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_LEFT) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_LEFT(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_LEFT makeVirtualKey_VK_LEFT() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_LEFT(fun_VirtualKey_VK_LEFT, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_LEFTFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_LEFT);

    if (children != null) {
      return makeVirtualKey_VK_LEFT(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_LEFT arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_LEFT, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_LEFT_PARENTHESIS makeVirtualKey_VK_LEFT_PARENTHESIS(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_LEFT_PARENTHESIS) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_LEFT_PARENTHESIS(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_LEFT_PARENTHESIS makeVirtualKey_VK_LEFT_PARENTHESIS() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_LEFT_PARENTHESIS(fun_VirtualKey_VK_LEFT_PARENTHESIS, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_LEFT_PARENTHESISFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_LEFT_PARENTHESIS);

    if (children != null) {
      return makeVirtualKey_VK_LEFT_PARENTHESIS(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_LEFT_PARENTHESIS arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_LEFT_PARENTHESIS, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_MINUS makeVirtualKey_VK_MINUS(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_MINUS) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_MINUS(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_MINUS makeVirtualKey_VK_MINUS() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_MINUS(fun_VirtualKey_VK_MINUS, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_MINUSFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_MINUS);

    if (children != null) {
      return makeVirtualKey_VK_MINUS(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_MINUS arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_MINUS, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_MULTIPLY makeVirtualKey_VK_MULTIPLY(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_MULTIPLY) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_MULTIPLY(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_MULTIPLY makeVirtualKey_VK_MULTIPLY() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_MULTIPLY(fun_VirtualKey_VK_MULTIPLY, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_MULTIPLYFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_MULTIPLY);

    if (children != null) {
      return makeVirtualKey_VK_MULTIPLY(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_MULTIPLY arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_MULTIPLY, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_NUMBER_SIGN makeVirtualKey_VK_NUMBER_SIGN(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_NUMBER_SIGN) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_NUMBER_SIGN(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_NUMBER_SIGN makeVirtualKey_VK_NUMBER_SIGN() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_NUMBER_SIGN(fun_VirtualKey_VK_NUMBER_SIGN, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_NUMBER_SIGNFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_NUMBER_SIGN);

    if (children != null) {
      return makeVirtualKey_VK_NUMBER_SIGN(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_NUMBER_SIGN arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_NUMBER_SIGN, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_OPEN_BRACKET makeVirtualKey_VK_OPEN_BRACKET(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_OPEN_BRACKET) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_OPEN_BRACKET(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_OPEN_BRACKET makeVirtualKey_VK_OPEN_BRACKET() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_OPEN_BRACKET(fun_VirtualKey_VK_OPEN_BRACKET, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_OPEN_BRACKETFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_OPEN_BRACKET);

    if (children != null) {
      return makeVirtualKey_VK_OPEN_BRACKET(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_OPEN_BRACKET arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_OPEN_BRACKET, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_PAGE_DOWN makeVirtualKey_VK_PAGE_DOWN(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_PAGE_DOWN) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_PAGE_DOWN(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_PAGE_DOWN makeVirtualKey_VK_PAGE_DOWN() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_PAGE_DOWN(fun_VirtualKey_VK_PAGE_DOWN, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_PAGE_DOWNFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_PAGE_DOWN);

    if (children != null) {
      return makeVirtualKey_VK_PAGE_DOWN(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_PAGE_DOWN arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_PAGE_DOWN, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_PAGE_UP makeVirtualKey_VK_PAGE_UP(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_PAGE_UP) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_PAGE_UP(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_PAGE_UP makeVirtualKey_VK_PAGE_UP() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_PAGE_UP(fun_VirtualKey_VK_PAGE_UP, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_PAGE_UPFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_PAGE_UP);

    if (children != null) {
      return makeVirtualKey_VK_PAGE_UP(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_PAGE_UP arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_PAGE_UP, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_PAUSE makeVirtualKey_VK_PAUSE(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_PAUSE) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_PAUSE(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_PAUSE makeVirtualKey_VK_PAUSE() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_PAUSE(fun_VirtualKey_VK_PAUSE, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_PAUSEFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_PAUSE);

    if (children != null) {
      return makeVirtualKey_VK_PAUSE(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_PAUSE arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_PAUSE, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_PERIOD makeVirtualKey_VK_PERIOD(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_PERIOD) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_PERIOD(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_PERIOD makeVirtualKey_VK_PERIOD() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_PERIOD(fun_VirtualKey_VK_PERIOD, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_PERIODFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_PERIOD);

    if (children != null) {
      return makeVirtualKey_VK_PERIOD(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_PERIOD arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_PERIOD, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_PLUS makeVirtualKey_VK_PLUS(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_PLUS) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_PLUS(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_PLUS makeVirtualKey_VK_PLUS() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_PLUS(fun_VirtualKey_VK_PLUS, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_PLUSFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_PLUS);

    if (children != null) {
      return makeVirtualKey_VK_PLUS(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_PLUS arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_PLUS, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_PRINTSCREEN makeVirtualKey_VK_PRINTSCREEN(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_PRINTSCREEN) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_PRINTSCREEN(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_PRINTSCREEN makeVirtualKey_VK_PRINTSCREEN() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_PRINTSCREEN(fun_VirtualKey_VK_PRINTSCREEN, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_PRINTSCREENFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_PRINTSCREEN);

    if (children != null) {
      return makeVirtualKey_VK_PRINTSCREEN(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_PRINTSCREEN arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_PRINTSCREEN, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_QUOTE makeVirtualKey_VK_QUOTE(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_QUOTE) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_QUOTE(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_QUOTE makeVirtualKey_VK_QUOTE() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_QUOTE(fun_VirtualKey_VK_QUOTE, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_QUOTEFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_QUOTE);

    if (children != null) {
      return makeVirtualKey_VK_QUOTE(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_QUOTE arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_QUOTE, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_QUOTEDBL makeVirtualKey_VK_QUOTEDBL(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_QUOTEDBL) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_QUOTEDBL(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_QUOTEDBL makeVirtualKey_VK_QUOTEDBL() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_QUOTEDBL(fun_VirtualKey_VK_QUOTEDBL, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_QUOTEDBLFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_QUOTEDBL);

    if (children != null) {
      return makeVirtualKey_VK_QUOTEDBL(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_QUOTEDBL arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_QUOTEDBL, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_RIGHT makeVirtualKey_VK_RIGHT(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_RIGHT) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_RIGHT(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_RIGHT makeVirtualKey_VK_RIGHT() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_RIGHT(fun_VirtualKey_VK_RIGHT, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_RIGHTFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_RIGHT);

    if (children != null) {
      return makeVirtualKey_VK_RIGHT(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_RIGHT arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_RIGHT, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_RIGHT_PARENTHESIS makeVirtualKey_VK_RIGHT_PARENTHESIS(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_RIGHT_PARENTHESIS) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_RIGHT_PARENTHESIS(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_RIGHT_PARENTHESIS makeVirtualKey_VK_RIGHT_PARENTHESIS() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_RIGHT_PARENTHESIS(fun_VirtualKey_VK_RIGHT_PARENTHESIS, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_RIGHT_PARENTHESISFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_RIGHT_PARENTHESIS);

    if (children != null) {
      return makeVirtualKey_VK_RIGHT_PARENTHESIS(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_RIGHT_PARENTHESIS arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_RIGHT_PARENTHESIS, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_SEMICOLON makeVirtualKey_VK_SEMICOLON(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_SEMICOLON) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_SEMICOLON(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_SEMICOLON makeVirtualKey_VK_SEMICOLON() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_SEMICOLON(fun_VirtualKey_VK_SEMICOLON, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_SEMICOLONFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_SEMICOLON);

    if (children != null) {
      return makeVirtualKey_VK_SEMICOLON(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_SEMICOLON arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_SEMICOLON, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_SLASH makeVirtualKey_VK_SLASH(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_SLASH) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_SLASH(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_SLASH makeVirtualKey_VK_SLASH() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_SLASH(fun_VirtualKey_VK_SLASH, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_SLASHFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_SLASH);

    if (children != null) {
      return makeVirtualKey_VK_SLASH(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_SLASH arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_SLASH, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_SPACE makeVirtualKey_VK_SPACE(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_SPACE) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_SPACE(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_SPACE makeVirtualKey_VK_SPACE() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_SPACE(fun_VirtualKey_VK_SPACE, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_SPACEFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_SPACE);

    if (children != null) {
      return makeVirtualKey_VK_SPACE(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_SPACE arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_SPACE, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_SUBTRACT makeVirtualKey_VK_SUBTRACT(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_SUBTRACT) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_SUBTRACT(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_SUBTRACT makeVirtualKey_VK_SUBTRACT() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_SUBTRACT(fun_VirtualKey_VK_SUBTRACT, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_SUBTRACTFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_SUBTRACT);

    if (children != null) {
      return makeVirtualKey_VK_SUBTRACT(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_SUBTRACT arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_SUBTRACT, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_TAB makeVirtualKey_VK_TAB(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_TAB) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_TAB(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_TAB makeVirtualKey_VK_TAB() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_TAB(fun_VirtualKey_VK_TAB, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_TABFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_TAB);

    if (children != null) {
      return makeVirtualKey_VK_TAB(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_TAB arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_TAB, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_UNDERSCORE makeVirtualKey_VK_UNDERSCORE(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_UNDERSCORE) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_UNDERSCORE(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_UNDERSCORE makeVirtualKey_VK_UNDERSCORE() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_UNDERSCORE(fun_VirtualKey_VK_UNDERSCORE, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_UNDERSCOREFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_UNDERSCORE);

    if (children != null) {
      return makeVirtualKey_VK_UNDERSCORE(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_UNDERSCORE arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_UNDERSCORE, args);
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_UP makeVirtualKey_VK_UP(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return (nl.cwi.sen1.configapi.types.virtualkey.VK_UP) factory.build( new nl.cwi.sen1.configapi.types.virtualkey.VK_UP(this, annos, fun, args));
  }

  public nl.cwi.sen1.configapi.types.virtualkey.VK_UP makeVirtualKey_VK_UP() {
    aterm.ATerm[] args = new aterm.ATerm[] {};
    return makeVirtualKey_VK_UP(fun_VirtualKey_VK_UP, args, factory.getEmpty());
  }

  protected nl.cwi.sen1.configapi.types.VirtualKey VirtualKey_VK_UPFromTerm(aterm.ATerm trm) {
    java.util.List<Object> children = trm.match(pattern_VirtualKey_VK_UP);

    if (children != null) {
      return makeVirtualKey_VK_UP(
      );
    }
    return null;
  }

  public aterm.ATerm toTerm(nl.cwi.sen1.configapi.types.virtualkey.VK_UP arg) {
    java.util.List<Object> args = new java.util.LinkedList<Object>();
    return factory.make(pattern_VirtualKey_VK_UP, args);
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
    tmp = KeyModifier_M_ALTFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = KeyModifier_M_CTRLFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = KeyModifier_M_SHIFTFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    throw new IllegalArgumentException("This is not a KeyModifier: " + trm);
  }

  public nl.cwi.sen1.configapi.types.VirtualKey VirtualKeyFromTerm(aterm.ATerm trm) {
    nl.cwi.sen1.configapi.types.VirtualKey tmp;
    tmp = VirtualKey_VK_0FromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_1FromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_2FromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_3FromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_4FromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_5FromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_6FromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_7FromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_8FromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_9FromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_AFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_BFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_CFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_DFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_EFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_FFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_GFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_HFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_IFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_JFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_KFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_LFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_MFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_NFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_OFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_PFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_QFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_RFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_SFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_TFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_UFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_VFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_WFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_XFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_YFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_ZFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_AMPERSANDFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_ASTERISKFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_ATFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_BACK_QUOTEFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_BACK_SLASHFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_BACK_SPACEFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_BEGINFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_BRACE_LEFTFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_BRACE_RIGHTFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_CIRCUMFLEXFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_CLEARFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_CLOSE_BRACKETFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_COLONFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_COMMAFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_DECIMALFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_DELETEFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_DIVIDEFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_DOLLARFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_DOWNFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_ENDFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_ENTERFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_EQUALSFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_ESCAPEFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_EXCLAMATION_MARKFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_F1FromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_F2FromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_F3FromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_F4FromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_F5FromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_F6FromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_F7FromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_F8FromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_F9FromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_F10FromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_F11FromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_F12FromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_GREATERFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_HOMEFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_INSERTFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_LEFTFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_LEFT_PARENTHESISFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_MINUSFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_MULTIPLYFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_NUMBER_SIGNFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_OPEN_BRACKETFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_PAGE_DOWNFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_PAGE_UPFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_PAUSEFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_PERIODFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_PLUSFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_PRINTSCREENFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_QUOTEFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_QUOTEDBLFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_RIGHTFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_RIGHT_PARENTHESISFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_SEMICOLONFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_SLASHFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_SPACEFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_SUBTRACTFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_TABFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_UNDERSCOREFromTerm(trm);
    if (tmp != null) {
      return tmp;
    }

    tmp = VirtualKey_VK_UPFromTerm(trm);
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

  public static char charToByte(Integer arg) {

      return((char) arg.intValue());
  }

  public static char charToByte(int arg) {

      return((char) arg);
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
