<?xml version="1.0" encoding="utf-8"?>

<xsl:stylesheet version="1.0"
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

    <xsl:output cdata-section-elements="elem12 elem22"/>

    <xsl:template match="elem1">
        <NEW-elem1>
            <xsl:comment> NEW<xsl:value-of select="comment()"/></xsl:comment>
            <NEW-elem11>NEW <xsl:value-of select="elem11"/></NEW-elem11>
            <NEW-elem12><xsl:value-of select="concat('NEW ', elem12)"/></NEW-elem12>
            <NEW-elem13>
                <NEW-elem131/>
                <NEW-elem132/>
            </NEW-elem13>
            <xsl:processing-instruction name="NEW-proc1"> NEW <xsl:value-of 
                select="processing-instruction()"/></xsl:processing-instruction>
        </NEW-elem1>
    </xsl:template>

    <xsl:template match="elem21">
        <NEW-elem21>NEW <xsl:value-of select="."/></NEW-elem21>
    </xsl:template>

    <xsl:template match="elem22">
        <NEW-elem22><xsl:value-of select="concat('NEW ', .)"/></NEW-elem22>
    </xsl:template>

</xsl:stylesheet>
