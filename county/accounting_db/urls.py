from django.urls import path

from . import views

urlpatterns = [
    path("", views.records, name="records"),
    path("accplan/", views.accplan, name="accplan"),
]
