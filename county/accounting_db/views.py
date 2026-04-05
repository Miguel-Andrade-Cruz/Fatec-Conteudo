from django.shortcuts import render

from .models import AccPlan, Fact


def records(request):

    records = Fact.objects.all()
    return render(request, "facts.html", {"facts": records})


def accplan(request):

    records = AccPlan.objects.select_related("segmentplan", "nicheplan").all()

    return render(request, "accplans.html", {"accplans": records})
