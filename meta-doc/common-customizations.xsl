<?xml version='1.0'?> 
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"  version="1.0"> 

<!-- Common definitions for DocBook XSL customization
     Put HTML customization in html-customization.xsl.src 
     (or, alternatively, in the CSS stylesheet that is used)

     Put FO (used for PDF generation) customization in fo-customization.xsl.src.
-->

<!-- chapter/section labeling -->
<xsl:param name="chapter.autolabel"          select="'1'" />
<xsl:param name="section.autolabel"          select="'1'" />

<!-- graphics -->
<xsl:param name="callout.graphics.path"      select="'../../images/callouts/'" />

<!-- cross referencing -->
<xsl:param name="xref.with.number.and.title" select="'1'" />
<xsl:param name="collect.xref.targets"       select= "'yes'" />
<xsl:param name="target.database.document"   select="'olinkdb.xml'" />
<xsl:param name="olink.doctitle"             select="'yes'" />
<!-- <xsl:param name="olink.debug"                select="'1'" /> -->

<!-- Adapt style of page number references in xrefs -->

<xsl:param name="local.l10n.xml" select="document('')"/>
<l:i18n xmlns:l="http://docbook.sourceforge.net/xmlns/l10n/1.0">
  <l:l10n language="en">
    <l:context name="xref">
      <l:template name="page.citation" text=" (p. %p)"/>
    </l:context>
  </l:l10n>
</l:i18n>

<!-- Started attempt to make title in xrefs italic rather than quoted -->

<xsl:param name="local.l10n.xml" select="document('')"/>
<l:i18n xmlns:l="http://docbook.sourceforge.net/xmlns/l10n/1.0">
  <l:l10n language="en">

  <l:context name="xref-number-and-title">
      <l:template name="appendix" text="Appendix&#160;%n, %t"/>
      <l:template name="bridgehead" text="Section&#160;%n, &#8220;%t&#8221;"/>
      <l:template name="chapter" text="Chapter&#160;%n, %t"/>
      <l:template name="equation" text="Equation&#160;%n, &#8220;%t&#8221;"/>
      <l:template name="example" text="Example&#160;%n, &#8220;%t&#8221;"/>
      <l:template name="figure" text="Figure&#160;%n, &lt;emphasis&gt;%t&lt;/emphasis&gt;"/>
      <l:template name="part" text="Part&#160;%n, &#8220;%t&#8221;"/>
      <l:template name="procedure" text="Procedure&#160;%n, &#8220;%t&#8221;"/>
      <l:template name="productionset" text="Production&#160;%n, &#8220;%t&#8221;"/>
      <l:template name="qandadiv" text="Q &amp; A&#160;%n, &#8220;%t&#8221;"/>
      <l:template name="refsect1" text="the section called &#8220;%t&#8221;"/>
      <l:template name="refsect2" text="the section called &#8220;%t&#8221;"/>
      <l:template name="refsect3" text="the section called &#8220;%t&#8221;"/>
      <l:template name="refsection" text="the section called &#8220;%t&#8221;"/>
      <l:template name="sect1" text="Section&#160;%n, &#8220;%t&#8221;"/>
      <l:template name="sect2" text="Section&#160;%n, &#8220;%t&#8221;"/>
      <l:template name="sect3" text="Section&#160;%n, &#8220;%t&#8221;"/>
      <l:template name="sect4" text="Section&#160;%n, &#8220;%t&#8221;"/>
      <l:template name="sect5" text="Section&#160;%n, &#8220;%t&#8221;"/>
      <l:template name="section" text="Section&#160;%n, &#8220;%t&#8221;"/>
      <l:template name="simplesect" text="the section called &#8220;%t&#8221;"/>
      <l:template name="table" text="Table&#160;%n, &#8220;%t&#8221;"/>
   </l:context>
  </l:l10n>
</l:i18n>


</xsl:stylesheet>  
