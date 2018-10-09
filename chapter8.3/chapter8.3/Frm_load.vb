﻿Imports System.Configuration

Public Class Frm_load

    Private Sub Btn_Connect_Click(sender As Object, e As EventArgs) Handles Btn_Connect.Click
        If Creo_Connect() <> True Then
            MsgBox("无法连接CREO对话！")
        Else
            Btn_LoadToolkitDll.Enabled = True
        End If
    End Sub

    Private Sub Btn_new_Click(sender As Object, e As EventArgs) Handles Btn_new.Click
        If Creo_New() <> True Then
            MsgBox("无法新建CREO对话！")
        Else
            Btn_LoadToolkitDll.Enabled = True
        End If
    End Sub

    Private Sub Frm_load_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        '设置相关路径，在App.config增加新配置了
        TKDLLName = ConfigurationManager.AppSettings("TKDLLName").ToString()
        DllPath = ConfigurationManager.AppSettings("DllPath").ToString()
        TextPath = ConfigurationManager.AppSettings("TextPath").ToString()
    End Sub

    Private Sub Btn_LoadToolkitDll_Click(sender As Object, e As EventArgs) Handles Btn_LoadToolkitDll.Click
        LoadToolkitDll()
    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Btn_ExcuteFun.Click
        ExecuteFunction(2)
    End Sub
End Class