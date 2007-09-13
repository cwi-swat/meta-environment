<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet 
  xmlns:xsl="http://www.w3.org/1999/XSL/Transform" 
  xmlns:db="http://docbook.org/ns/docbook"
  version="1.0">

  <xsl:param name="now" />
  <xsl:output omit-xml-declaration="no" indent="yes" encoding="UTF-8" method="xml" />       

    <xsl:template match="node()|@*">
      <xsl:copy>
	<xsl:apply-templates select="@*"/>
	<xsl:apply-templates/>
      </xsl:copy>
    </xsl:template>

    <xsl:template match="db:pubdate">
      <pubdate>
	<xsl:value-of select="$now" />
      </pubdate>
    </xsl:template>

</xsl:stylesheet>
