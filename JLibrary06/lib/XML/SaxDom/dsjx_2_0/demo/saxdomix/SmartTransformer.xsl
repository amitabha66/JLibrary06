<?xml version="1.0" encoding="utf-8"?>

<xsl:stylesheet version="1.0"
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

    <xsl:template match="row">
        <record>
            <painter><xsl:value-of select="@painter"/></painter>
            <title><xsl:value-of select="@title"/></title>
            <year><xsl:value-of select="@year"/></year>
            <size><xsl:value-of select="@size"/></size>
        </record>
    </xsl:template>

</xsl:stylesheet>
