#include "ParsedErrors_dict.h"

AFun PME_afun39;
AFun PME_afun17;
AFun PME_afun22;
AFun PME_afun44;
AFun PME_afun3;
AFun PME_afun9;
AFun PME_afun34;
AFun PME_afun19;
AFun PME_afun26;
AFun PME_afun37;
AFun PME_afun2;
AFun PME_afun41;
AFun PME_afun12;
AFun PME_afun42;
AFun PME_afun15;
AFun PME_afun25;
AFun PME_afun18;
AFun PME_afun20;
AFun PME_afun31;
AFun PME_afun8;
AFun PME_afun28;
AFun PME_afun43;
AFun PME_afun21;
AFun PME_afun32;
AFun PME_afun0;
AFun PME_afun11;
AFun PME_afun5;
AFun PME_afun27;
AFun PME_afun33;
AFun PME_afun38;
AFun PME_afun16;
AFun PME_afun10;
AFun PME_afun13;
AFun PME_afun4;
AFun PME_afun14;
AFun PME_afun40;
AFun PME_afun23;
AFun PME_afun30;
AFun PME_afun45;
AFun PME_afun7;
AFun PME_afun36;
AFun PME_afun24;
AFun PME_afun35;
AFun PME_afun29;
AFun PME_afun46;
AFun PME_afun1;
AFun PME_afun6;

ATerm PME_patternOptLayoutPresent = NULL;
ATerm PME_patternOptLayoutAbsent = NULL;
ATerm PME_patternStartError = NULL;
ATerm PME_patternStartFatalError = NULL;
ATerm PME_patternStartWarning = NULL;
ATerm PME_patternStartInformation = NULL;
ATerm PME_patternStartProducer = NULL;
ATerm PME_patternStartDescription = NULL;
ATerm PME_patternStartFeedback = NULL;
ATerm PME_patternStartLocation = NULL;
ATerm PME_patternStartArea = NULL;
ATerm PME_patternAreaArea = NULL;
ATerm PME_patternLocationLocation = NULL;
ATerm PME_patternSubjectWithLocation = NULL;
ATerm PME_patternSubjectWithoutLocation = NULL;
ATerm PME_patternSubjectSubjectListSingle = NULL;
ATerm PME_patternSubjectSubjectListEmpty = NULL;
ATerm PME_patternSubjectSubjectListMany = NULL;
ATerm PME_patternSubjectsSubjects = NULL;
ATerm PME_patternDescriptionDescription = NULL;
ATerm PME_patternProducerProducer = NULL;
ATerm PME_patternFatalErrorFatalError = NULL;
ATerm PME_patternErrorError = NULL;
ATerm PME_patternWarningWarning = NULL;
ATerm PME_patternInformationInformation = NULL;
ATerm PME_patternFeedbackFatalError = NULL;
ATerm PME_patternFeedbackError = NULL;
ATerm PME_patternFeedbackWarning = NULL;
ATerm PME_patternFeedbackInfo = NULL;

/*
 * PME_afun39 = "with-location"
 * PME_afun17 = ")"
 * PME_afun22 = "Description"
 * PME_afun44 = parsetree(x,x)
 * PME_afun3 = sort(x)
 * PME_afun9 = "info"
 * PME_afun34 = "subjects"
 * PME_afun19 = layout
 * PME_afun26 = "information"
 * PME_afun37 = "subject"
 * PME_afun2 = cf(x)
 * PME_afun41 = "location"
 * PME_afun12 = "Error"
 * PME_afun42 = "NatCon"
 * PME_afun15 = "fatal-error"
 * PME_afun25 = "("
 * PME_afun18 = opt(x)
 * PME_afun20 = "Subjects"
 * PME_afun31 = iter-star-sep(x,x)
 * PME_afun8 = cons(x)
 * PME_afun28 = "producer"
 * PME_afun43 = "area"
 * PME_afun21 = ","
 * PME_afun32 = "Subject"
 * PME_afun0 = appl(x,x)
 * PME_afun11 = "warning"
 * PME_afun5 = "Feedback"
 * PME_afun27 = "Information"
 * PME_afun33 = "["
 * PME_afun38 = "without-location"
 * PME_afun16 = lit(x)
 * PME_afun10 = "Warning"
 * PME_afun13 = "error"
 * PME_afun4 = "Info"
 * PME_afun14 = "FatalError"
 * PME_afun40 = "Area"
 * PME_afun23 = "Producer"
 * PME_afun30 = "]"
 * PME_afun45 = "<START>"
 * PME_afun7 = term(x)
 * PME_afun36 = "Location"
 * PME_afun24 = "String"
 * PME_afun35 = list(x)
 * PME_afun29 = "description"
 * PME_afun46 = no-attrs
 * PME_afun1 = prod(x,x,x)
 * PME_afun6 = attrs(x)
 *
 * PME_patternOptLayoutPresent = appl(prod([cf(layout)],cf(opt(layout)),no-attrs),<term>)
 * PME_patternOptLayoutAbsent = appl(prod([],cf(opt(layout)),no-attrs),[])
 * PME_patternStartError = parsetree(appl(prod([cf(opt(layout)),cf(sort("Error")),cf(opt(layout))],sort("<START>"),no-attrs),[<term>,<term>,<term>]),<int>)
 * PME_patternStartFatalError = parsetree(appl(prod([cf(opt(layout)),cf(sort("FatalError")),cf(opt(layout))],sort("<START>"),no-attrs),[<term>,<term>,<term>]),<int>)
 * PME_patternStartWarning = parsetree(appl(prod([cf(opt(layout)),cf(sort("Warning")),cf(opt(layout))],sort("<START>"),no-attrs),[<term>,<term>,<term>]),<int>)
 * PME_patternStartInformation = parsetree(appl(prod([cf(opt(layout)),cf(sort("Information")),cf(opt(layout))],sort("<START>"),no-attrs),[<term>,<term>,<term>]),<int>)
 * PME_patternStartProducer = parsetree(appl(prod([cf(opt(layout)),cf(sort("Producer")),cf(opt(layout))],sort("<START>"),no-attrs),[<term>,<term>,<term>]),<int>)
 * PME_patternStartDescription = parsetree(appl(prod([cf(opt(layout)),cf(sort("Description")),cf(opt(layout))],sort("<START>"),no-attrs),[<term>,<term>,<term>]),<int>)
 * PME_patternStartFeedback = parsetree(appl(prod([cf(opt(layout)),cf(sort("Feedback")),cf(opt(layout))],sort("<START>"),no-attrs),[<term>,<term>,<term>]),<int>)
 * PME_patternStartLocation = parsetree(appl(prod([cf(opt(layout)),cf(sort("Location")),cf(opt(layout))],sort("<START>"),no-attrs),[<term>,<term>,<term>]),<int>)
 * PME_patternStartArea = parsetree(appl(prod([cf(opt(layout)),cf(sort("Area")),cf(opt(layout))],sort("<START>"),no-attrs),[<term>,<term>,<term>]),<int>)
 * PME_patternAreaArea = appl(prod([lit("area"),cf(opt(layout)),lit("("),cf(opt(layout)),cf(sort("NatCon")),cf(opt(layout)),lit(","),cf(opt(layout)),cf(sort("NatCon")),cf(opt(layout)),lit(","),cf(opt(layout)),cf(sort("NatCon")),cf(opt(layout)),lit(","),cf(opt(layout)),cf(sort("NatCon")),cf(opt(layout)),lit(","),cf(opt(layout)),cf(sort("NatCon")),cf(opt(layout)),lit(","),cf(opt(layout)),cf(sort("NatCon")),cf(opt(layout)),lit(")")],cf(sort("Area")),attrs([term(cons("area"))])),[lit("area"),<term>,lit("("),<term>,<term>,<term>,lit(","),<term>,<term>,<term>,lit(","),<term>,<term>,<term>,lit(","),<term>,<term>,<term>,lit(","),<term>,<term>,<term>,lit(","),<term>,<term>,<term>,lit(")")])
 * PME_patternLocationLocation = appl(prod([lit("location"),cf(opt(layout)),lit("("),cf(opt(layout)),cf(sort("String")),cf(opt(layout)),lit(","),cf(opt(layout)),cf(sort("Area")),cf(opt(layout)),lit(")")],cf(sort("Location")),attrs([term(cons("location"))])),[lit("location"),<term>,lit("("),<term>,<term>,<term>,lit(","),<term>,<term>,<term>,lit(")")])
 * PME_patternSubjectWithLocation = appl(prod([lit("subject"),cf(opt(layout)),lit("("),cf(opt(layout)),cf(sort("String")),cf(opt(layout)),lit(")")],cf(sort("Subject")),attrs([term(cons("with-location"))])),[lit("subject"),<term>,lit("("),<term>,<term>,<term>,lit(")")])
 * PME_patternSubjectWithoutLocation = appl(prod([lit("subject"),cf(opt(layout)),lit("("),cf(opt(layout)),cf(sort("String")),cf(opt(layout)),lit(","),cf(opt(layout)),cf(sort("Location")),cf(opt(layout)),lit(")")],cf(sort("Subject")),attrs([term(cons("without-location"))])),[lit("subject"),<term>,lit("("),<term>,<term>,<term>,lit(","),<term>,<term>,<term>,lit(")")])
 * PME_patternSubjectSubjectListSingle = [<term>]
 * PME_patternSubjectSubjectListEmpty = []
 * PME_patternSubjectSubjectListMany = [<term>,<term>,lit(<str>),<term>,<list>]
 * PME_patternSubjectsSubjects = appl(prod([lit("["),cf(opt(layout)),cf(iter-star-sep(sort("Subject"),lit(","))),cf(opt(layout)),lit("]")],cf(sort("Subjects")),attrs([term(cons("subjects"))])),[lit("["),<term>,appl(list(cf(iter-star-sep(sort("Subject"),lit(",")))),<term>),<term>,lit("]")])
 * PME_patternDescriptionDescription = appl(prod([lit("description"),cf(opt(layout)),lit("("),cf(opt(layout)),cf(sort("String")),cf(opt(layout)),lit(")")],cf(sort("Description")),attrs([term(cons("description"))])),[lit("description"),<term>,lit("("),<term>,<term>,<term>,lit(")")])
 * PME_patternProducerProducer = appl(prod([lit("producer"),cf(opt(layout)),lit("("),cf(opt(layout)),cf(sort("String")),cf(opt(layout)),lit(","),cf(opt(layout)),cf(sort("String")),cf(opt(layout)),lit(")")],cf(sort("Producer")),attrs([term(cons("producer"))])),[lit("producer"),<term>,lit("("),<term>,<term>,<term>,lit(","),<term>,<term>,<term>,lit(")")])
 * PME_patternFatalErrorFatalError = appl(prod([lit("fatal-error"),cf(opt(layout)),lit("("),cf(opt(layout)),cf(sort("String")),cf(opt(layout)),lit(","),cf(opt(layout)),cf(sort("Producer")),cf(opt(layout)),lit(","),cf(opt(layout)),cf(sort("Description")),cf(opt(layout)),lit(","),cf(opt(layout)),cf(sort("Subjects")),cf(opt(layout)),lit(")")],cf(sort("FatalError")),attrs([term(cons("fatal-error"))])),[lit("fatal-error"),<term>,lit("("),<term>,<term>,<term>,lit(","),<term>,<term>,<term>,lit(","),<term>,<term>,<term>,lit(","),<term>,<term>,<term>,lit(")")])
 * PME_patternErrorError = appl(prod([lit("error"),cf(opt(layout)),lit("("),cf(opt(layout)),cf(sort("String")),cf(opt(layout)),lit(","),cf(opt(layout)),cf(sort("Producer")),cf(opt(layout)),lit(","),cf(opt(layout)),cf(sort("Description")),cf(opt(layout)),lit(","),cf(opt(layout)),cf(sort("Subjects")),cf(opt(layout)),lit(")")],cf(sort("Error")),attrs([term(cons("error"))])),[lit("error"),<term>,lit("("),<term>,<term>,<term>,lit(","),<term>,<term>,<term>,lit(","),<term>,<term>,<term>,lit(","),<term>,<term>,<term>,lit(")")])
 * PME_patternWarningWarning = appl(prod([lit("warning"),cf(opt(layout)),lit("("),cf(opt(layout)),cf(sort("String")),cf(opt(layout)),lit(","),cf(opt(layout)),cf(sort("Producer")),cf(opt(layout)),lit(","),cf(opt(layout)),cf(sort("Description")),cf(opt(layout)),lit(","),cf(opt(layout)),cf(sort("Subjects")),cf(opt(layout)),lit(")")],cf(sort("Warning")),attrs([term(cons("warning"))])),[lit("warning"),<term>,lit("("),<term>,<term>,<term>,lit(","),<term>,<term>,<term>,lit(","),<term>,<term>,<term>,lit(","),<term>,<term>,<term>,lit(")")])
 * PME_patternInformationInformation = appl(prod([lit("information"),cf(opt(layout)),lit("("),cf(opt(layout)),cf(sort("String")),cf(opt(layout)),lit(","),cf(opt(layout)),cf(sort("Producer")),cf(opt(layout)),lit(","),cf(opt(layout)),cf(sort("Description")),cf(opt(layout)),lit(","),cf(opt(layout)),cf(sort("Subjects")),cf(opt(layout)),lit(")")],cf(sort("Information")),attrs([term(cons("information"))])),[lit("information"),<term>,lit("("),<term>,<term>,<term>,lit(","),<term>,<term>,<term>,lit(","),<term>,<term>,<term>,lit(","),<term>,<term>,<term>,lit(")")])
 * PME_patternFeedbackFatalError = appl(prod([cf(sort("FatalError"))],cf(sort("Feedback")),attrs([term(cons("fatal-error"))])),[<term>])
 * PME_patternFeedbackError = appl(prod([cf(sort("Error"))],cf(sort("Feedback")),attrs([term(cons("error"))])),[<term>])
 * PME_patternFeedbackWarning = appl(prod([cf(sort("Warning"))],cf(sort("Feedback")),attrs([term(cons("warning"))])),[<term>])
 * PME_patternFeedbackInfo = appl(prod([cf(sort("Info"))],cf(sort("Feedback")),attrs([term(cons("info"))])),[<term>])
 *
 */

static ATerm _ParsedErrors_dict = NULL;

#define _ParsedErrors_dict_LEN 1527

static char _ParsedErrors_dict_baf[_ParsedErrors_dict_LEN] = {
0x00,0x8B,0xAF,0x83,0x00,0x37,0x81,0xC7,0x03,0x3C,0x5F,0x3E,0x01,0x00,0x04,0x04,
0x05,0x04,0x03,0x06,0x05,0x5B,0x5F,0x2C,0x5F,0x5D,0x02,0x00,0x80,0xFA,0x32,0x02,
0x01,0x00,0x07,0x08,0x09,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,
0x16,0x17,0x18,0x19,0x1A,0x1B,0x1C,0x1D,0x1E,0x1F,0x20,0x21,0x22,0x23,0x24,0x25,
0x26,0x27,0x28,0x29,0x2A,0x2B,0x2C,0x2D,0x2E,0x2F,0x30,0x31,0x32,0x33,0x34,0x35,
0x36,0x02,0x01,0x02,0x02,0x5B,0x5D,0x00,0x00,0x01,0x03,0x69,0x6E,0x74,0x00,0x00,
0x01,0x03,0x73,0x74,0x72,0x00,0x00,0x01,0x04,0x6C,0x69,0x73,0x74,0x00,0x00,0x01,
0x04,0x74,0x65,0x72,0x6D,0x00,0x00,0x01,0x0D,0x77,0x69,0x74,0x68,0x2D,0x6C,0x6F,
0x63,0x61,0x74,0x69,0x6F,0x6E,0x00,0x01,0x01,0x01,0x29,0x00,0x01,0x01,0x0B,0x44,
0x65,0x73,0x63,0x72,0x69,0x70,0x74,0x69,0x6F,0x6E,0x00,0x01,0x01,0x01,0x78,0x00,
0x00,0x01,0x09,0x70,0x61,0x72,0x73,0x65,0x74,0x72,0x65,0x65,0x02,0x00,0x0A,0x02,
0x20,0x0A,0x02,0x00,0x0A,0x04,0x73,0x6F,0x72,0x74,0x01,0x00,0x10,0x10,0x29,0x19,
0x1F,0x31,0x15,0x2B,0x30,0x22,0x09,0x2C,0x23,0x27,0x2A,0x2E,0x14,0x0A,0x04,0x69,
0x6E,0x66,0x6F,0x00,0x01,0x01,0x08,0x73,0x75,0x62,0x6A,0x65,0x63,0x74,0x73,0x00,
0x01,0x01,0x06,0x6C,0x61,0x79,0x6F,0x75,0x74,0x00,0x00,0x01,0x0B,0x69,0x6E,0x66,
0x6F,0x72,0x6D,0x61,0x74,0x69,0x6F,0x6E,0x00,0x01,0x01,0x07,0x73,0x75,0x62,0x6A,
0x65,0x63,0x74,0x00,0x01,0x01,0x02,0x63,0x66,0x01,0x00,0x12,0x05,0x1A,0x0C,0x18,
0x0F,0x0A,0x08,0x6C,0x6F,0x63,0x61,0x74,0x69,0x6F,0x6E,0x00,0x01,0x01,0x05,0x45,
0x72,0x72,0x6F,0x72,0x00,0x01,0x01,0x06,0x4E,0x61,0x74,0x43,0x6F,0x6E,0x00,0x01,
0x01,0x0B,0x66,0x61,0x74,0x61,0x6C,0x2D,0x65,0x72,0x72,0x6F,0x72,0x00,0x01,0x01,
0x01,0x28,0x00,0x01,0x01,0x03,0x6F,0x70,0x74,0x01,0x00,0x02,0x02,0x0F,0x0A,0x08,
0x53,0x75,0x62,0x6A,0x65,0x63,0x74,0x73,0x00,0x01,0x01,0x0D,0x69,0x74,0x65,0x72,
0x2D,0x73,0x74,0x61,0x72,0x2D,0x73,0x65,0x70,0x02,0x00,0x02,0x02,0x0C,0x0A,0x02,
0x26,0x0A,0x04,0x63,0x6F,0x6E,0x73,0x01,0x00,0x0D,0x0D,0x0D,0x10,0x21,0x28,0x16,
0x1C,0x33,0x0E,0x25,0x07,0x13,0x1D,0x0A,0x08,0x70,0x72,0x6F,0x64,0x75,0x63,0x65,
0x72,0x00,0x01,0x01,0x04,0x61,0x72,0x65,0x61,0x00,0x01,0x01,0x01,0x2C,0x00,0x01,
0x01,0x07,0x53,0x75,0x62,0x6A,0x65,0x63,0x74,0x00,0x01,0x01,0x04,0x61,0x70,0x70,
0x6C,0x02,0x00,0x1C,0x03,0x32,0x35,0x0A,0x04,0x01,0x02,0x00,0x0A,0x07,0x77,0x61,
0x72,0x6E,0x69,0x6E,0x67,0x00,0x01,0x01,0x08,0x46,0x65,0x65,0x64,0x62,0x61,0x63,
0x6B,0x00,0x01,0x01,0x0B,0x49,0x6E,0x66,0x6F,0x72,0x6D,0x61,0x74,0x69,0x6F,0x6E,
0x00,0x01,0x01,0x01,0x5B,0x00,0x01,0x01,0x10,0x77,0x69,0x74,0x68,0x6F,0x75,0x74,
0x2D,0x6C,0x6F,0x63,0x61,0x74,0x69,0x6F,0x6E,0x00,0x01,0x01,0x03,0x6C,0x69,0x74,
0x01,0x00,0x10,0x10,0x10,0x21,0x28,0x16,0x1C,0x33,0x2D,0x24,0x00,0x11,0x13,0x08,
0x1E,0x17,0x1D,0x0A,0x07,0x57,0x61,0x72,0x6E,0x69,0x6E,0x67,0x00,0x01,0x01,0x05,
0x65,0x72,0x72,0x6F,0x72,0x00,0x01,0x01,0x04,0x49,0x6E,0x66,0x6F,0x00,0x01,0x01,
0x0A,0x46,0x61,0x74,0x61,0x6C,0x45,0x72,0x72,0x6F,0x72,0x00,0x01,0x01,0x04,0x41,
0x72,0x65,0x61,0x00,0x01,0x01,0x08,0x50,0x72,0x6F,0x64,0x75,0x63,0x65,0x72,0x00,
0x01,0x01,0x01,0x5D,0x00,0x01,0x01,0x07,0x3C,0x53,0x54,0x41,0x52,0x54,0x3E,0x00,
0x01,0x01,0x04,0x74,0x65,0x72,0x6D,0x01,0x00,0x0D,0x02,0x1B,0x0A,0x08,0x4C,0x6F,
0x63,0x61,0x74,0x69,0x6F,0x6E,0x00,0x01,0x01,0x06,0x53,0x74,0x72,0x69,0x6E,0x67,
0x00,0x01,0x01,0x04,0x6C,0x69,0x73,0x74,0x01,0x00,0x02,0x02,0x12,0x0A,0x0B,0x64,
0x65,0x73,0x63,0x72,0x69,0x70,0x74,0x69,0x6F,0x6E,0x00,0x01,0x01,0x08,0x6E,0x6F,
0x2D,0x61,0x74,0x74,0x72,0x73,0x00,0x00,0x01,0x04,0x70,0x72,0x6F,0x64,0x03,0x00,
0x1B,0x03,0x02,0x01,0x0A,0x03,0x0C,0x12,0x0A,0x03,0x36,0x34,0x0A,0x05,0x61,0x74,
0x74,0x72,0x73,0x01,0x00,0x0D,0x02,0x01,0x0A,0x01,0x81,0xD3,0x02,0xD0,0x80,0xD2,
0x83,0x51,0x80,0xA1,0x53,0x80,0x78,0x94,0x10,0x14,0x90,0xE4,0x50,0x64,0xD0,0xA4,
0x30,0x24,0xB0,0x04,0xC4,0x70,0x44,0xF0,0x84,0x08,0x04,0x88,0xF8,0x48,0x78,0xC8,
0x8B,0x82,0x83,0x8A,0x8A,0x36,0x1A,0x03,0x16,0x3A,0x26,0x06,0x06,0x26,0x3A,0x16,
0x1A,0x36,0x03,0x8A,0x83,0x82,0x8B,0x8C,0x87,0x84,0x8F,0x88,0x80,0x40,0x88,0x41,
0xE3,0xC1,0x11,0xC3,0x12,0xC0,0x90,0xC2,0x93,0x41,0x91,0x43,0x92,0x40,0x50,0x42,
0x53,0x81,0x50,0x86,0x0D,0x4A,0x03,0x42,0x0B,0x48,0xC0,0x74,0x40,0xF4,0x80,0x0C,
0x0A,0x80,0x11,0x85,0x03,0xF0,0x77,0xED,0x0A,0x17,0xA5,0x90,0xD4,0x85,0x12,0x18,
0x6F,0xD9,0x12,0x09,0x14,0x2B,0xD8,0x83,0x16,0x24,0xCB,0x10,0x46,0x59,0x89,0x07,
0x01,0x96,0x22,0x11,0x68,0x56,0x20,0x02,0xC4,0x01,0x98,0x80,0x88,0x82,0xF6,0x10,
0x24,0x4B,0xB2,0xC4,0x0D,0x96,0x12,0x60,0xC0,0x60,0x88,0x56,0x10,0xCF,0x63,0x0A,
0x54,0xA7,0x2C,0x40,0x39,0x65,0x21,0x34,0x06,0x08,0x85,0x61,0x04,0xF6,0x08,0x64,
0xCB,0x72,0xC4,0x0B,0x96,0x32,0x51,0x40,0x60,0x88,0x56,0x10,0x8F,0x62,0x8E,0x5C,
0xAF,0x2C,0x40,0x79,0x67,0x23,0x24,0x06,0x08,0x85,0x61,0x00,0xF6,0x18,0x14,0x2B,
0xF2,0xC4,0x0F,0x96,0x0A,0x70,0x40,0x60,0x88,0x56,0x10,0xF7,0x63,0x89,0x52,0xA0,
0xAC,0x40,0x05,0x64,0xA0,0xB8,0x06,0x08,0x85,0x61,0x07,0x76,0x04,0x54,0xAB,0x0A,
0xC4,0x08,0x56,0x2A,0x49,0x80,0x60,0x88,0x56,0x10,0xB7,0x62,0x4D,0x5A,0xA8,0xAC,
0x40,0x45,0x66,0xA2,0xA8,0x06,0x08,0x85,0x61,0x03,0x7D,0x8D,0x1A,0x06,0x86,0x0E,
0x3E,0xAC,0x40,0xF5,0x0A,0x2C,0x5D,0x58,0x80,0xEA,0xC3,0x4D,0x10,0xDA,0xB1,0x02,
0xD4,0x38,0x31,0x35,0x62,0x01,0xAB,0x0C,0x75,0x58,0x81,0xAA,0x1C,0x15,0x56,0x20,
0x2A,0xB0,0xC6,0x55,0x88,0x12,0xA1,0xC1,0x15,0x62,0x00,0xAB,0x0C,0x79,0x58,0x81,
0xCA,0x1C,0x16,0x56,0x20,0x32,0xB0,0xC6,0x95,0x88,0x14,0xA1,0xC1,0x25,0x62,0x01,
0x2B,0x0C,0x71,0x58,0x81,0x8A,0x12,0x6A,0xB4,0x41,0x0C,0xAC,0x11,0xB0,0xDE,0x86,
0x02,0xF2,0x00,0x9E,0x85,0x00,0xF2,0x00,0xEE,0x40,0x0D,0xC8,0x02,0xBA,0x1C,0x05,
0xC8,0x03,0x39,0x00,0x27,0x20,0x08,0xE8,0x70,0x07,0x20,0x0F,0x64,0x00,0xEC,0x80,
0x2D,0xA1,0xC0,0x6C,0x80,0x35,0x90,0x02,0xB2,0x00,0x96,0x87,0x00,0xB2,0x00,0xE6,
0x40,0x0C,0xC8,0x02,0x9A,0x1C,0x04,0xC8,0x03,0x19,0x00,0x23,0x20,0x06,0x23,0x5F,
0x6B,0x56,0x88,0x61,0xA2,0x8C,0x1B,0x10,0x20,0xC2,0x82,0x06,0xC4,0x00,0x36,0x5A,
0x1B,0x07,0xF5,0x88,0x1F,0xA1,0xC1,0x7D,0x62,0x03,0xEB,0x34,0x71,0x4A,0x10,0xA1,
0x55,0x04,0x58,0x08,0xC3,0x43,0x85,0x00,0x30,0xC2,0x80,0x58,0x57,0xD9,0xD3,0xAB,
0x18,0x59,0x20,0xC6,0xC4,0x1A,0x30,0xA0,0x51,0xB1,0x04,0x8D,0x96,0x38,0xA7,0x4B,
0x20,0xC1,0xC5,0x5C,0x32,0x61,0x13,0x0B,0x00,0x94,0x01,0xE3,0x0A,0x02,0x62,0x5F,
0x6F,0x5E,0x96,0x61,0x61,0x33,0x62,0x01,0x98,0x50,0x74,0xD8,0x81,0xA6,0xCB,0x15,
0x36,0x20,0x29,0x87,0x06,0x4D,0x88,0x12,0x6C,0x51,0xC5,0x38,0x23,0x65,0x52,0x08,
0x60,0x73,0x0B,0x0E,0x10,0x5E,0x0C,0xC3,0x9C,0x01,0x9E,0x08,0x54,0x00,0x0A,0x80,
0x3E,0x61,0xE0,0x94,0x1E,0x50,0x05,0xCA,0x18,0x45,0x3E,0xD1,0x83,0x32,0xC2,0x2E,
0x14,0xB6,0x20,0x25,0xB3,0xC2,0x2C,0x60,0xC5,0xB1,0x02,0x2C,0x32,0x65,0x06,0x3A,
0x05,0x1C,0xAA,0xD1,0x5D,0x0D,0x58,0x44,0x2A,0xA0,0x09,0x5D,0x82,0x47,0x90,0x05,
0x50,0x02,0x28,0x4F,0xB2,0x68,0xC6,0xB0,0xAA,0x81,0x8C,0x21,0x8B,0x55,0x58,0x66,
0x83,0xAC,0x2A,0x02,0x4C,0x7D,0xB3,0x26,0xAD,0x87,0x44,0x0B,0x6C,0x41,0x9B,0x0A,
0x04,0xDB,0x10,0x46,0xD9,0x60,0x36,0xC4,0x1E,0xB0,0xE0,0x51,0xB8,0x70,0xDA,0xAF,
0x1D,0x50,0xED,0x87,0x47,0x08,0x8F,0xB1,0x6C,0xC2,0x70,0x9B,0x07,0x1D,0x88,0x18,
0xE1,0x41,0x47,0x62,0x02,0x3B,0x2C,0x61,0xD8,0x81,0x0E,0x1C,0x10,0x76,0x20,0x03,
0xB3,0x87,0xED,0x88,0x1F,0x61,0xC1,0x7B,0x62,0x03,0xDB,0x04,0x6E,0xD8,0x81,0x76,
0x1C,0x13,0xB6,0x20,0x1D,0xB0,0x27,0x14,0x40,0x49,0x35,0x44,0x12,0x81,0x9C,0x26,
0x34,0xD0,0x02,0x9C,0x28,0x03,0x88,0x7D,0xAB,0x16,0xB3,0x86,0xC8,0x38,0xEC,0x12,
0x39,0xAB,0x24,0xE4,0x3C,0xE1,0xB1,0xA6,0x03,0xEC,0xDA,0xB0,0x5C,0x2E,0x81,0xC7,
0x50,0x52,0x2D,0x55,0x15,0x20,0x97,0x0B,0x8D,0x33,0xEF,0x6E,0xCD,0xB2,0xE1,0xF0,
0x0E,0x39,0x86,0x85,0x6A,0xE9,0xB1,0x0A,0xB8,0x7C,0x69,0x8F,0x7B,0x0E,0xEC,0xD7,
0x61,0x2A,0x40,0x8C,0xC2,0xEF,0x69,0xC3,0xBA,0xEC,0xC5,0x48,0x91,0x98,0x1D,0xEC,
0xBA,0x70,0xDD,0x94,0xA9,0x0A,0x33,0x0D,0xBD,0xB7,0x2E,0x9B,0xB2,0x33,0xC0,0xA9,
0x06,0x2D,0xAA,0x61,0x84,0x33,0x28
};

void init_ParsedErrors_dict()
{
  ATermList afuns, terms;

  _ParsedErrors_dict = ATreadFromBinaryString(_ParsedErrors_dict_baf, _ParsedErrors_dict_LEN);

  ATprotect(&_ParsedErrors_dict);

  afuns = (ATermList)ATelementAt((ATermList)_ParsedErrors_dict, 0);

  PME_afun39 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PME_afun17 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PME_afun22 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PME_afun44 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PME_afun3 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PME_afun9 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PME_afun34 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PME_afun19 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PME_afun26 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PME_afun37 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PME_afun2 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PME_afun41 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PME_afun12 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PME_afun42 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PME_afun15 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PME_afun25 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PME_afun18 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PME_afun20 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PME_afun31 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PME_afun8 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PME_afun28 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PME_afun43 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PME_afun21 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PME_afun32 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PME_afun0 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PME_afun11 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PME_afun5 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PME_afun27 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PME_afun33 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PME_afun38 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PME_afun16 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PME_afun10 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PME_afun13 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PME_afun4 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PME_afun14 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PME_afun40 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PME_afun23 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PME_afun30 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PME_afun45 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PME_afun7 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PME_afun36 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PME_afun24 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PME_afun35 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PME_afun29 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PME_afun46 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PME_afun1 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PME_afun6 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);

  terms = (ATermList)ATelementAt((ATermList)_ParsedErrors_dict, 1);

  PME_patternOptLayoutPresent = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PME_patternOptLayoutAbsent = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PME_patternStartError = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PME_patternStartFatalError = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PME_patternStartWarning = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PME_patternStartInformation = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PME_patternStartProducer = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PME_patternStartDescription = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PME_patternStartFeedback = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PME_patternStartLocation = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PME_patternStartArea = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PME_patternAreaArea = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PME_patternLocationLocation = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PME_patternSubjectWithLocation = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PME_patternSubjectWithoutLocation = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PME_patternSubjectSubjectListSingle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PME_patternSubjectSubjectListEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PME_patternSubjectSubjectListMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PME_patternSubjectsSubjects = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PME_patternDescriptionDescription = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PME_patternProducerProducer = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PME_patternFatalErrorFatalError = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PME_patternErrorError = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PME_patternWarningWarning = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PME_patternInformationInformation = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PME_patternFeedbackFatalError = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PME_patternFeedbackError = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PME_patternFeedbackWarning = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PME_patternFeedbackInfo = ATgetFirst(terms);
  terms = ATgetNext(terms);
}
