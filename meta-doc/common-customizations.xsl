<?xml version='1.0'?> 
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"  version="1.0"> 

<!-- Common definitions for DocBook XSL customization
     Put HTML customization in html-customization.xsl.src 
     (or, alternatively, in the CSS stylesheet that is used)

     Put FO (used for PDF generation) customization in fo-customization.xsl.src.
-->

<!-- chapter/section labeling -->
<xsl:param name="chapter.autolabel"          select="'1'" />
<xsl:param name="section.autolabel"          select="'0'" />
<xsl:param name="figure.autolabel"           select="'0'" />
<xsl:param name="table.autolabel"            select="'0'" />

<!-- graphics -->
<xsl:param name="callout.graphics.path"      select="'../../images/callouts/'" />

<!-- cross referencing -->
<xsl:param name="xref.with.number.and.title" select="'1'" />
<xsl:param name="collect.xref.targets"       select= "'yes'" />
<xsl:param name="target.database.document"   select="'olinkdb.xml'" />
<xsl:param name="olink.doctitle"             select="'yes'" />

<!-- bibliography -->
<xsl:param name="bibliography.collection"    select="'/home/paulk/research/meta-doc/trunk/getting-started/4-bibliography/bibliography.xml'"/>

<!-- Adapt style of page number references in xrefs -->

<xsl:param name="local.l10n.xml" select="document('')"/>
<l:i18n xmlns:l="http://docbook.sourceforge.net/xmlns/l10n/1.0">
  <l:l10n language="en">
    <l:context name="xref">
      <l:template name="page.citation" text=" (p. %p)"/>
    </l:context>
  </l:l10n>
</l:i18n>

</xsl:stylesheet>  
