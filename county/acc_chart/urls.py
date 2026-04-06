from django.urls import path

from . import views

app_name = "chart"

urlpatterns = [
    # path('testing/', views.testing_show_chart_codes, name="testing_chart"),
    # path('testingform/', views.testing_form_chart, name="form_testing_chart")
    path('', views.home, name="home"),
    path('/novo', views.form, name="form")
]
