package nl.dancingbear.visplugin;

//Java tool interface VisualizationPluginTif
//This file is generated automatically, please do not edit!
//generation time: Mar 12, 2007 12:24:08 PM


import aterm.*;

public interface VisualizationPluginTif
{
public void vpFileDialogResult(int i0, String s1);
public void vpVisualizeFact(int i0, int i1, ATerm t2);
public void vpFileDialogCancel(int i0);
public void vpFactOutOfDate(int i0, int i1);
public ATerm vpGetName();
public ATerm vpIsTypeSupported(ATerm t0);
public void recAckEvent(ATerm t0);
public void recTerminate(ATerm t0);
}

