<?xml version="1.0" encoding="utf-8"?>

<xsl:stylesheet version="1.0"
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

    <xsl:template match="record">
        <tr>
            <td><xsl:value-of select="painter"/></td>
            <td><xsl:value-of select="title"/></td>
            <td><xsl:value-of select="year"/></td>
            <td><xsl:value-of select="size"/></td>
        </tr>
    </xsl:template>

</xsl:stylesheet>
