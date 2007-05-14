<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
    "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:date="http://exslt.org/dates-and-times" xmlns:func="http://exslt.org/functions" xmlns:str="http://exslt.org/strings" extension-element-prefixes="date func str" version="1.0">

    <xsl:output omit-xml-declaration="no" indent="yes" encoding="UTF-8" method="xml" />       
    
    <xsl:template match="log">
      <html>
	<body>
	  <table border="1">
	    <tr>
	      <td>
		Date
	      </td>
	      <td>
		Author
	      </td>
	      <td>
		Message
	      </td>
	    </tr> 
	    <xsl:apply-templates select="logentry" />
	  </table>
	</body>
      </html>
    </xsl:template>
    
    <xsl:template match="logentry">
      <tr>
	<td>
	  <xsl:call-template name="rfc822">
	    <xsl:with-param name="isodate" select="date" />
	  </xsl:call-template>
	</td>
	<td>
	    <xsl:value-of select="author" />
	</td>
	<td>
	  <pre>
	    <xsl:value-of select="msg" /> 
	  </pre>
	</td>
      </tr>
    </xsl:template>

    <xsl:template name="rfc822">
        <xsl:param name="isodate" />
        <xsl:variable name="dayOfWeek" select="date:day-abbreviation($isodate)" />
        <xsl:variable name="day" select="date:day-in-month($isodate)" />
        <xsl:variable name="monthAbbr" select="date:month-abbreviation($isodate)" />
        <xsl:variable name="year" select="date:year($isodate)" />
        <xsl:variable name="hour" select="date:hour-in-day($isodate)" />
        <xsl:variable name="minute" select="date:minute-in-hour($isodate)" />
        <xsl:variable name="second" select="round(date:second-in-minute($isodate))" />

        <xsl:value-of select="$dayOfWeek" />
        <xsl:text>, </xsl:text>
        <xsl:value-of select="$day" />
        <xsl:text> </xsl:text>
        <xsl:value-of select="$monthAbbr" />
        <xsl:text> </xsl:text>
        <xsl:value-of select="$year" />
        <xsl:choose>
            <xsl:when test="$hour and $minute and $second">
                <xsl:text> </xsl:text>
                <xsl:value-of select="str:align($hour, '00', 'right')" />
                <xsl:text>:</xsl:text>
                <xsl:value-of select="str:align($minute, '00', 'right')" />
                <xsl:text>:</xsl:text>
                <xsl:value-of select="str:align($second, '00', 'right')" />
                <xsl:text> GMT</xsl:text>
            </xsl:when>
            <xsl:otherwise>
                <xsl:text> 00:00:00 GMT</xsl:text>
            </xsl:otherwise>
        </xsl:choose>
    </xsl:template>
    
</xsl:stylesheet>
