<?xml version='1.0'?>
<xsl:stylesheet  
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform" 
    xmlns:fo="http://www.w3.org/1999/XSL/Format"
    version="1.0">

<!-- FO- and complete-book specific customizations are defined here -->

<xsl:import href="fo-customization.xsl" />

<!-- graphics -->

<xsl:param name="callout.graphics.path"      select="'./images/callouts/'" />

<xsl:param name="body.font.family"           select="'serif,Symbol'"/>

</xsl:stylesheet>
